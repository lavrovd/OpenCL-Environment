/***********************************************************************
 *    Title:  init.c
 *    Author: Erik Rainey
 *    Date:   04/26/99
 ***********************************************************************/

/***********************************************************************
 *INCLUDE
 ***********************************************************************/

#include "SpaceTime.h"

/***********************************************************************
 *DEFINE
 ***********************************************************************/



/***********************************************************************
 *MACRO's
 ***********************************************************************/



/***********************************************************************
 *STATICS (VAR's, PROTOTYPES, and STRUCTS)
 ***********************************************************************/



/***********************************************************************
 *GLOBAL FUNCTIONS
 ***********************************************************************/

void init(int reinit)
{
    int i,j,k;

    memset(&body1,0,sizeof(Body));
#ifdef TEXTURES
    for(i=0;i<64;i++)
    {
        for(j=0;j<64;j++)
        {
            body1.texture[i][j].r = 255;
            body1.texture[i][j].g = 255;
            body1.texture[i][j].b = 0;
            body1.texture[i][j].a = 255;
        }
    }
#endif
    body1.mass = pow(10,20);
    body1.radius = 10;
    body1.v.x = 2;

    memset(&unit_body,0,sizeof(Body));
    unit_body.mass = 1;

    // init the SpaceTime Grid
    printf("Filling in the Space Time Grid with initial values! %ux%ux%u\n",X_DIM,Y_DIM,Z_DIM);
    for(i=0;i<X_DIM;i++)
    {
        for(j=0;j<Y_DIM;j++)
        {
            for(k=0;k<Z_DIM;k++)
            {
                STGrid[i][j][k].p.x = 10*(i-X_DIM/2);
                STGrid[i][j][k].p.y = 10*(j-Y_DIM/2);
                STGrid[i][j][k].p.z = 10*(k-Z_DIM/2);
                STGrid[i][j][k].f.x = 0;
                STGrid[i][j][k].f.y = 0;
                STGrid[i][j][k].f.z = 0;
            }
        }
    }

    RenderText = 1;
    RenderLines = 0;
    RenderHelp = 0;
    RenderMovement = 0;

    if (reinit != 0)
        return;

    initcamera();
    initscreen();
}

/***********************************************************************
 *STATIC FUNCTIONS
 ***********************************************************************/




/***********************************************************************
 *END
 ***********************************************************************/
