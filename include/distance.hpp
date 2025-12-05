#pragma once

namespace mik {
    enum class distance_position { FRONT_SENSOR, REAR_SENSOR, LEFT_SENSOR, RIGHT_SENSOR };
    enum class wall_position { TOP_WALL, BOTTOM_WALL, LEFT_WALL, RIGHT_WALL };

    bool reset_axis(distance_position sensor_pos,
                    wall_position wall_pos,
                    float max_reset_distance);
}
