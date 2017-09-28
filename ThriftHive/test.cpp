#include<stdio.h>
#include <stdlib.h>
#include "HiveClient.h"

int main(int argc, char* argv[])
{
	HiveClient hiveCli("126.10.12.120", "10000");
	if (hiveCli.HiveConnect())
	{
		return 0;
	}
	system("pause");
	return 0;
}