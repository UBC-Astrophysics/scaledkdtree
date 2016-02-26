#include <stdio.h>
#include <string.h>
#include "scaled_kdtree.h"

int
main(int argc, char *argv[]) {
  float dist;
  FILE *in;
  char buffer[1024];
  struct kdtree *kd;
  struct kdres *res;
  float pos[3], irpos[3];
#define MAXCOLUMNS 100
  char *optline, *inputstring, **ap, *argv2[MAXCOLUMNS];
  int j,loadon;
  double metric[3];
  
  in=stdin;
  loadon=1;
  kd = kd_create(3);

  while (fgets(buffer,1023,in)) {
    if (buffer[0]=='*') loadon=1-loadon;
    if (buffer[0]=='#' || buffer[0]=='*' || !loadon) {
      fputs(buffer,stdout);
    } else {
      sscanf(buffer,"%g %g %g\n",pos,pos+1,pos+2);
      optline=strdup(buffer);
      if (kd_insertf(kd, pos, (void *) optline)) {
	printf("Unable to insert point into the tree at  __FILE__:__LINENO__\n");
	return -1;
      }
    }
    /*    printf("%ld %g %g\n",xptr-xopt,*(xptr-1),*(yptr-1));  */
  }
  if (in!=stdin) fclose(in);

  irpos[0]=0; irpos[1]=0; irpos[2]=0;

  printf("no metric\n");
  
  res=kd_nearestf(kd,irpos);
  if (kd_res_size(res)>0) {
    optline = (char *) kd_res_itemf( res, pos );
    printf("%g %g %g -> %g %g %g\n",irpos[0],irpos[1],irpos[2],pos[0],pos[1],pos[2]);
  }
  kd_res_free(res);

  metric[0]=1; 
  metric[1]=1; 
  metric[2]=1;
  kd_set_metric(metric);
  
  printf("metric: %g %g %g\n",metric[0],metric[1],metric[2]);
  res=kd_nearestf(kd,irpos);
  if (kd_res_size(res)>0) {
    optline = (char *) kd_res_itemf( res, pos );
    printf("%g %g %g -> %g %g %g\n",irpos[0],irpos[1],irpos[2],pos[0],pos[1],pos[2]);
  }
  kd_res_free(res);

  metric[0]=0; 
  metric[1]=0; 
  metric[2]=1;
  kd_set_metric(metric);
  
  printf("metric: %g %g %g\n",metric[0],metric[1],metric[2]);
  res=kd_nearestf(kd,irpos);
  if (kd_res_size(res)>0) {
    optline = (char *) kd_res_itemf( res, pos );
    printf("%g %g %g -> %g %g %g\n",irpos[0],irpos[1],irpos[2],pos[0],pos[1],pos[2]);
  }
  kd_res_free(res);

  metric[0]=0; 
  metric[1]=1; 
  metric[2]=1;
  kd_set_metric(metric);
  
  printf("metric: %g %g %g\n",metric[0],metric[1],metric[2]);
  res=kd_nearestf(kd,irpos);
  if (kd_res_size(res)>0) {
    optline = (char *) kd_res_itemf( res, pos );
    printf("%g %g %g -> %g %g %g\n",irpos[0],irpos[1],irpos[2],pos[0],pos[1],pos[2]);
  }
  kd_res_free(res);

  metric[0]=1; 
  metric[1]=0; 
  metric[2]=1;
  kd_set_metric(metric);
  
  printf("metric: %g %g %g\n",metric[0],metric[1],metric[2]);
  res=kd_nearestf(kd,irpos);
  if (kd_res_size(res)>0) {
    optline = (char *) kd_res_itemf( res, pos );
    printf("%g %g %g -> %g %g %g\n",irpos[0],irpos[1],irpos[2],pos[0],pos[1],pos[2]);
  }
  kd_res_free(res);
return 0;
}
