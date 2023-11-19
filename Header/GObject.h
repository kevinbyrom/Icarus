#ifndef __GOBJECT_H
#define __GOBJECT_H


#define DIR_RIGHT	0
#define DIR_LEFT	1


class GOBJECT
	{
	public:

		GOBJECT()			{ State			= 0;
							  Dir			= DIR_RIGHT;
							  Wx			= 0;
							  Wy			= 0;
							  VelX			= 0;
							  VelY			= 0;
							  MaxVelX		= 0;
							  MaxVelY		= 0;
							  AccelX		= 0;
							  AccelY		= 0;
							  DeltaX		= 1;
							  DeltaY		= 0;
							  Mass			= 0;
							  pAnim			= NULL;
							  AnimPos		= 0;
							  AnimCtn		= 0;
							  AnimCtnMax	= 0;
							  Translucent	= 0;
							  Visible		= 1;
							}

		int State;			// State of the object
		int Dir;			// Direction of object
			
		int Wx, Wy;			// World X & World Y

		int VelX;			// Velocity of X change
		int VelY;			// Velocity of Y change
		int MaxVelX;		// Maximum velocity of X change
		int MaxVelY;		// Maximum velocity of Y change
		int AccelX;			// Acceleration of X velocity
		int AccelY;			// Acceleration of Y velocity
		int DeltaX;			// Direction of X change
		int DeltaY;			// Direction of Y change

		int Mass;			// Object mass (for gravity)
		
		int * pAnim;		// Animation array pointer
		int AnimPos;		// Animation position
		int AnimCnt;		// Animation counter
		int AnimCntMax;		// Animation counter max

		int Translucent;	// Translucent graphic flag
		int Visible;		// Visible graphic flag
	};



#endif