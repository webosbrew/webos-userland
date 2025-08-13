#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>
#include <functional>
#include <typeinfo>

namespace cdm   { struct InputBuffer_2; }
namespace wvcdm { struct InputBuffer; }

namespace svp
{
class InbandSerializerImpl
{
  public:
    virtual ~InbandSerializerImpl() = default;
    virtual bool DoConfigure(const uint8_t*, size_t,
                             const std::function<bool(std::vector<uint8_t>*,void*)>&,
                             void*) = 0;
    bool DoSerialize(std::vector<uint8_t>*);
};

// pulled in from stub or the real .so at link time
std::shared_ptr<InbandSerializerImpl> CreateInbandSerializerImpl(void*, const std::type_info&);

template<typename T>
class InbandSerializer
{
public:
  InbandSerializer()
    : impl_(CreateInbandSerializerImpl(static_cast<void*>(this), typeid(T)))
  {}

  ~InbandSerializer()
  {}

  /**
  * @param obj current instance of InbandSerializerImplReal<bool>
  * @param data raw media buffer
  * @param size size of media buffer
  * @param callBack callback to configure output vector
  * @param context opaque user context
  */
  bool Configure(const T &obj,
                 const uint8_t *data,
                 uint32_t size,
                 const std::function<bool(std::vector<uint8_t>*,void*)>&callBack = nullptr,
                 void *context = nullptr)
  {
    if (!impl_) return false;
    obj_ = obj;
    return impl_->DoConfigure(data, size, callBack, context);
  }

  bool GetSerialized(std::vector<uint8_t>* out)
  {
    if (!impl_ || !out) return false;
    return impl_->DoSerialize(out);
  }

  bool CanDoSerialize() { return impl_ != nullptr; }

  const T& encryption_info() const { return obj_; }

private:
  T obj_;
  std::shared_ptr<InbandSerializerImpl> impl_;

  void operator=(const InbandSerializer&);
};

} // namespace svp
