
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
	char *path = "libplugin.so";
	void *dl;
	void (*fxn)(void);

	if (argc > 1) {
		path = argv[1];
	}

	dl = dlopen(path, RTLD_NOW | RTLD_LOCAL);
	if (!dl) {
		printf("could not load '%s': %s'\n", path, dlerror());
		return -1;
	}

	fxn = dlsym(dl, "fxn");

	printf("going to call plugin function\n");
	fxn();
	printf("done calling plugin function\n");

	return 0;
}
