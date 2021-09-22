#pragma once

#include "botcraft/AI/BehaviourTree.hpp"
#include "botcraft/AI/BehaviourClient.hpp"

#include "botcraft/Game/Vector3.hpp"

namespace Botcraft
{
    namespace AI
    {
        /// <summary>
        /// Tries to dig a block at a given location. Must be in range.
        /// </summary>
        /// <param name="client">The client performing the action</param>
        /// <param name="pos">Location of block to dig</param>
        /// <param name="face">Digging direction</param>
        /// <returns>Success if the block was mined, Failure otherwise</returns>
        Status Dig(BehaviourClient& client, const Position& pos, const PlayerDiggingFace face = PlayerDiggingFace::Top);

        /// <summary>
        /// Dig that reads parameter from the blackboard
        /// </summary>
        /// <param name="client">The client performing the action</param>
        /// <returns>Success if the block was mined, Failure otherwise</returns>
        Status DigBlackboard(BehaviourClient& client);
    }
}