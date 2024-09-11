#include "vex.h"
#include "Autonomous/odometry.h"

#include <iostream>

// Initialize Odometry Class

Odometry::Odometry(double tracking_radius, double forward_tracking_distance, double sideways_tracking_distance, double start_heading, double start_x_pos, double start_y_pos) 
{
    // User Defined Values
    
    TrackingWheelRadius = tracking_radius;
    ForwardTrackingDistance = forward_tracking_distance;
    SidewaysTrackingDistance = sideways_tracking_distance;

    GlobalXPos = start_x_pos;
    GlobalYPos = start_y_pos;
    Heading = start_heading;

    headingInRadians = start_heading * M_PI / 180.0;
    previousHeadingInRadians = start_heading * M_PI / 180.0;

    // Math Values

    // Travel of tracking wheels (INCHES)

    forwardPos = 0;
    sidewaysPos = 0;

    previousForwardPos = 0;
    previousSidewaysPos = 0;

    // Distance travelled per loop (INCHES)

    deltaForward = 0;
    deltaSideways = 0;

    // Distance summations (INCHES)

    totalDeltaForward = 0;
    totalDeltaSideways = 0;

     // Change in Heading (RADIANS)

    deltaHeadingInRadians = 0;
    averageHeadingForArc = 0;

    // Local Position Change (INCHES)

    deltaXLocal = 0;
    deltaYLocal = 0;

    // Global Position Change (INCHES)

    deltaXGlobal = 0;
    deltaYGlobal = 0;
}

// Update Odometry

void Odometry::Update(void) {
    // Rotation Sensor Values (DEGREES)
    forwardPos = forwardTrackingWheel.position(rotationUnits::deg);
    sidewaysPos = sidewaysTrackingWheel.position(rotationUnits::deg);

    // Converts degrees to RADIANS, then calculates distance travelled (INCHES)
    deltaForward = ((forwardPos - previousForwardPos) * M_PI / 180) * TrackingWheelRadius;
    deltaSideways = ((sidewaysPos - previousSidewaysPos) * M_PI / 180) * TrackingWheelRadius;

    // Updates previous sensor values (DEGREES)
    previousForwardPos = forwardPos;
    previousSidewaysPos = sidewaysPos;

    // Total change in encoders (INCHES)
    totalDeltaForward += deltaForward;
    totalDeltaSideways += deltaSideways;

    // Saves robot heading (DEGREES)
    Heading = inertial_sensor.heading(rotationUnits::deg);

    // Saves robot heding (RADIANS)
    headingInRadians = Heading * M_PI / 180.0;

    // Calculates change in angle in RADIANS 
    deltaHeadingInRadians = headingInRadians - previousHeadingInRadians;

    // Updates previous orientation in RADIANS
    previousHeadingInRadians = headingInRadians;

    if (deltaHeadingInRadians == 0) { // If no rotation, it was just a translation
        deltaXLocal = deltaSideways;
        deltaYLocal = deltaForward;
    } else { // Else, do some boring math
        deltaXLocal = 2 * sin(deltaHeadingInRadians / 2.0) * ((deltaSideways / deltaHeadingInRadians) + SidewaysTrackingDistance);
        deltaYLocal = 2 * sin(deltaHeadingInRadians / 2.0) * ((deltaForward / deltaHeadingInRadians) - ForwardTrackingDistance); 
    }

    // Average heading for this arc (RADIANS)
    averageHeadingForArc = headingInRadians - (deltaHeadingInRadians / 2);

    // Gets change in X and Y position (INCHES)
    deltaXGlobal = (deltaYLocal * sin(averageHeadingForArc)) + (deltaXLocal * cos(averageHeadingForArc));
    deltaYGlobal = (deltaYLocal * cos(averageHeadingForArc)) - (deltaXLocal * sin(averageHeadingForArc));

    GlobalXPos += deltaXGlobal;
    GlobalYPos += deltaYGlobal;
}

// Update Odometry Task

int UpdateOdometry(void) {
    while (true) {
        wait(50, msec);
        Position_Tracking.Update();
    }

    return 1;
}