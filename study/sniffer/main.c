#include "snf_common.h"

int main(){
	char  errbuf[PCAP_ERRBUF_SIZE];
	char* device;

	device = pcap_lookupdev(errbuf);
	if (!device){
		printf("error: pcap_lookupdev(): %s\n", errbuf);
		exit (1);
	}

	printf("device is %s\n", device);

	if (snf_show_net_info(device) != SNF_OK){
		printf("error: snf_show_net_info():\n");
		return SNF_ERROR;
	}

	return SNF_OK;
}
