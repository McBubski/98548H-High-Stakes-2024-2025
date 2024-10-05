/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Odometry.h                                                */
/*    Author:       Team 98548H (Revamped)                                    */
/*    Created:      9-10-2024                                                 */
/*    Description:  Header file for Odometry                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#pragma once

class Odometry
{
private:
    // Travel of tracking wheels (INCHES)

    double forwardPos;
    double sidewaysPos;

    double previousForwardPos;
    double previousSidewaysPos;

    // Distance travelled per loop (INCHES)

    double deltaForward;
    double deltaSideways;

    // Distance summations (INCHES)

    double totalDeltaForward;
    double totalDeltaSideways;

    // Heading (RADIANS)
    
    double previousHeadingInRadians;

    // Change in Heading (RADIANS)

    double headingInRadians;
    double deltaHeadingInRadians;
    double averageHeadingForArc;

    // Local Position Change (INCHES)

    double deltaXLocal;
    double deltaYLocal;

    // Global Position Change (INCHES)

    double deltaXGlobal;
    double deltaYGlobal;
    
public:
    // User Defined Values, Inches unless otherwise noted.

    double TrackingWheelRadius;
    double StartOrientation;

    double ForwardTrackingDistance;
    double SidewaysTrackingDistance;

    // Global Robot Values

    double Heading;
    double GlobalXPos;
    double GlobalYPos;

    Odometry(double tracking_radius, double forward_tracking_distance, double sideways_tracking_distance, double start_orientation, double start_x_pos, double start_y_pos);

    void Update(void);
    void SetAuton(int path);
};

int UpdateOdometry(void);