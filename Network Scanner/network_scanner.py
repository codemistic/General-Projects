


'''
$$\   $$\            $$\                                       $$\              $$$$$$\                                                             
$$$\  $$ |           $$ |                                      $$ |            $$  __$$\                                                            
$$$$\ $$ | $$$$$$\ $$$$$$\   $$\  $$\  $$\  $$$$$$\   $$$$$$\  $$ |  $$\       $$ /  \__| $$$$$$$\ $$$$$$\  $$$$$$$\  $$$$$$$\   $$$$$$\   $$$$$$\  
$$ $$\$$ |$$  __$$\\_$$  _|  $$ | $$ | $$ |$$  __$$\ $$  __$$\ $$ | $$  |      \$$$$$$\  $$  _____|\____$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ 
$$ \$$$$ |$$$$$$$$ | $$ |    $$ | $$ | $$ |$$ /  $$ |$$ |  \__|$$$$$$  /        \____$$\ $$ /      $$$$$$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$ |$$ |  \__|
$$ |\$$$ |$$   ____| $$ |$$\ $$ | $$ | $$ |$$ |  $$ |$$ |      $$  _$$<        $$\   $$ |$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$   ____|$$ |      
$$ | \$$ |\$$$$$$$\  \$$$$  |\$$$$$\$$$$  |\$$$$$$  |$$ |      $$ | \$$\       \$$$$$$  |\$$$$$$$\\$$$$$$$ |$$ |  $$ |$$ |  $$ |\$$$$$$$\ $$ |      
\__|  \__| \_______|  \____/  \_____\____/  \______/ \__|      \__|  \__|       \______/  \_______|\_______|\__|  \__|\__|  \__| \_______|\__|      
                                                                                                                                                    
                                                                                                                                                    
                                                                                                                                                    
 ~ Abhinandan Khurana																		   '''



#!/usr/bin/env python

import scapy.all as scapy
import argparse

# Get the arguments from the command line
def get_arguments():
	parser = argparse.ArgumentParser()
	parser.add_argument("-t", "--target", dest="ip", help="Enter IP address or IP address range of target network")
	options = parser.parse_args()
	if not options.ip:
		parser.error("[-] Please specify an IP address or IP address range, use --help for more info")
	return options

# Scan the network for clients
def scan(ip):
	# ARP request generation
	arp_request = scapy.ARP(pdst=ip)
	# Ethernet frame generation for ARP broadcast to src MAC address
	broadcast = scapy.Ether(dst="ff:ff:ff:ff:ff:ff")
	# Combined the two frames for easily sending the packet
	arp_request_broadcast = broadcast/arp_request
	# Send the packet and get the response (remember the response is in the form of a list, and those are 2 specifically - answered and unanswered ), we need to get the first element of the list so we used answered[0]
	answered_list = scapy.srp(arp_request_broadcast, timeout=1, verbose=False)[0]
	# list comprehension to get the MAC address and IP address of the client (contains nested dictionaries)
	client_list = []
	for element in answered_list:
		client_dict = {"ip": element[1].psrc, "mac": element[1].hwsrc}
		client_list.append(client_dict)
	return client_list


# Print the results
def print_result(result_list):
	print("IP\t\t\tMAC_Address\n------------------------------------------")
	for client in result_list:
		print(client["ip"] + "\t\t" + client["mac"])




# Main function
options=get_arguments()
scan_result = scan(options.ip)
print_result(scan_result)