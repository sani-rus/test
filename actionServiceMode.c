#include <stdio.h>
#include "wra.h"
#include <string.h>
#include <stdlib.h>
#define APP_NAME     "serviceMode"

int app_main(void *dev, const char *appname, const char *args)
{
    (void)dev;
    if (!appname)
    {
        printf(" appname is empty \n");
        return WRA_ERR_BAD_PARAM;
    }

    if (strncmp(appname,APP_NAME,sizeof(APP_NAME)))
    {
        printf(" bad appname %s . My app name is %s\n",appname,APP_NAME);
        return WRA_ERR_BAD_PARAM;
    }
	
	printf("Stopping data delivery.\n");
	system("pkill -SIGSTOP dataApp");
	
    return WRA_SUCCESS;
}
int action_subscription()
{
  wra_handle wra_h;       /* Agent handle         */

  /* Get a handle to the agent */
  wra_h = wra_gethandle();

  if(wra_h == WRA_NULL) 
  {
    printf("We failed to get agent handle\n");
    return WRA_ERR_FAILED;
  }
  
  if (wra_action_subscribe(wra_h,app_main,APP_NAME) != WRA_SUCCESS)
  {
	  printf("failed to subscribe application %s \n",APP_NAME);
  }else

while (1)

	 if (wra_action_wait(wra_h,NULL) != WRA_SUCCESS)
	 {
	      printf("failed to execute  the action\n");
	 }
  
 /* delete the handle if while (1) is not used above */
  if (wra_delete_handle(wra_h)!=WRA_SUCCESS)
  {
      printf("failed to cleanup the handle\n");
      return WRA_ERR_FAILED;
  }
  return WRA_SUCCESS;
}

int main(int argc, char **argv)
{
	action_subscription();
	return 0;
}
