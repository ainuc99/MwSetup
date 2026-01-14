#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mwvd.h"

#define VD_IOCTL_DEV "/dev/mwvd-control"

void usage(const char *progname)
{
  fprintf(stderr, "Usage: %s <option> mwvd_dev {img_file}\n", progname);
  fprintf(stderr, "\t -c : create vdisk with image file\n");
  fprintf(stderr, "\t -d : delete vdisk & detach image file\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
  int lfd, ffd, ret;

  if (argc < 3)
    usage(argv[0]);

  /**
   * open mwvd device
   */
  lfd = open(argv[2], O_RDWR);
  if (lfd < 0)
  {
    perror("ioctl open");
    exit(EXIT_FAILURE);
  }

  if (strcmp(argv[1], "-c") == 0)
  {
    /**
     * open image file
     */
    ffd = open(argv[3], O_RDWR);
    if (ffd < 0)
    {
      perror("file open");
      return ffd;
    }
    /**
     * set fd
     */
    ret = ioctl(lfd, MWVD_SET_FD, ffd);
    if (ret < 0)
      perror("ioctl create");
    else
      printf("attach image file ok.\n");
  }
  else if (strcmp(argv[1], "-d") == 0)
  {
    /**
     * clear fd
     */
    ret = ioctl(lfd, MWVD_CLR_FD, 0);
    if (ret < 0)
      perror("ioctl delete");
    else
      printf("detach image file ok.\n");
    close(lfd);
  }
  else
  {
    usage(argv[0]);
  }

  return 0;
}
