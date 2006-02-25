/*
 * Copyright (c) 2003, 2006 Matteo Frigo
 * Copyright (c) 2003, 2006 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <string.h>
#include <stdio.h>

#include "my-getopt.h"

int my_optind = 1;
const char *my_optarg = 0;

void my_usage(const char *progname, const struct my_option *opt)
{
    int i;
    int col = 0;

    fprintf(stdout, "Usage: %s", progname);
    col += (strlen(progname) + 7);
    for (i = 0; opt[i].long_name; i++) {
	int option_len;

	option_len = strlen(opt[i].long_name);
	if (col >= 80 - (option_len + 16)) {
	    fputs("\n\t", stdout);
	    col = 8;
	}
	fprintf(stdout, " [--%s", opt[i].long_name);
	col += (option_len + 4);
	if (opt[i].short_name < 128) {
	    fprintf(stdout, " | -%c", opt[i].short_name);
	    col += 5;
	}
	switch (opt[i].argtype) {
	    case REQARG:
		 fputs(" arg]", stdout);
		 col += 5;
		 break;
	    case OPTARG:
		 fputs(" [arg(s)]]", stdout);
		 col += 10;
		 break;
	    default:
		 fputs("]", stdout);
		 col++;
	}
    }

    fputs ("\n", stdout);
}

int my_getopt(int argc, char *argv[], const struct my_option *optarray)
{
     const char *p;
     const struct my_option *l;

     if (my_optind >= argc)
	  return -1; /* no more options */

     p = argv[my_optind];

     if (*p++ != '-')  
	  return (-1); /* not an option */

     ++my_optind;
     my_optarg = 0;

     if (*p == '-') {
	  /* long option */
	  ++p;
	  
	  for (l = optarray; l->short_name; ++l) {
	       int len = strlen(l->long_name);
	       if (!strncmp(l->long_name, p, len) && 
		   (!p[len] || p[len] == '=')) {
		    switch (l->argtype) {
			case NOARG: 
		    ok:
			     return l->short_name;
			case OPTARG: 
			     if (p[len] == '=')
				  my_optarg = p + len + 1;
			     goto ok;
			case REQARG: 
			     if (p[len] == '=') {
				  my_optarg = p + len + 1;
				  goto ok;
			     }
			     if (my_optind >= argc) {
				  fprintf(stderr, 
					  "option --%s requires an argument\n",
					  l->long_name);
				  return '?';
			     }
			     my_optarg = argv[my_optind];
			     ++my_optind;
			     goto ok;
		    }
	       }
	  }

	  goto bad;
     } else {
	  /* short option */
	  for (l = optarray; l->short_name; ++l) {
	       if (l->short_name == (char)l->short_name &&
		   *p == l->short_name) {
		    ++p;
		    switch (l->argtype) {
			case NOARG: 
		    ok1:
			     return l->short_name;
			case OPTARG: 
			     if (*p)
				  my_optarg = p;
			     goto ok1;
			case REQARG: 
			     if (*p) {
				  my_optarg = p;
				  goto ok1;
			     }
			     if (my_optind >= argc) {
				  fprintf(stderr, 
					  "option -%c requires an argument\n",
					  l->short_name);
				  return '?';
			     }
			     my_optarg = argv[my_optind];
			     ++my_optind;
			     goto ok1;
		    }
	       }
	  }
     bad:
	  fprintf(stderr, "unrecognized option %s\n", argv[my_optind - 1]);
	  return '?';
     }
}
