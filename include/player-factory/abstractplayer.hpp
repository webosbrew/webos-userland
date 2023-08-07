#pragma once

#include <boost/shared_ptr.hpp>
#include <player-factory/player.hpp>

namespace mediapipeline {

class AbstractPlayer : public Player {
public:
  boost::shared_ptr<Pipeline> getPipeline() const;
};

}
