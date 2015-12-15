#include "snf_show_net_info.h"

int snf_show_net_info(char* device){
	char errbuf[PCAP_ERRBUF_SIZE];
	bpf_u_int32 netp;
	bpf_u_int32 maskp;
	struct in_addr addr;
	char* net;

	if (pcap_lookupnet(device, &netp, &maskp, errbuf) < 0){
		printf("error pcap_lookupnet(): %s\n", errbuf);
		return SNF_ERROR;
	}
	
	printf("netp is %d, maskp is %d\n", netp, maskp);
	
	addr.s_addr = netp;
	net = inet_ntoa(addr);
	if (net == NULL){
		printf("error inet_ntoa(): \n");
		return SNF_ERROR;
	}
	printf("netp is: %s\n", net);

	addr.s_addr = maskp;
	net = inet_ntoa(addr);
	if (net == NULL){
		printf("error inet_ntoa(): \n");
		return SNF_ERROR;
	}
	printf("maskp is: %s\n", net);

	return SNF_OK;
}
