#-*- coding: utf-8 -*-


print("=================================================")
print("==========목마른 자가 우물 파는 계산기==================")
print("=================================================")


while (True) :
	ip = input('IP address input : ').strip().split('.')
	tmp = ip[3].split('/')
	del ip[3]
	ip.append(tmp[0])
	ip.append(tmp[1])

	bin_ip = []

	for i in range (0, 4) :
		bin_ip.append(bin(int(ip[i])))
		bin_ip[i] = bin_ip[i][2:]
		bin_len = len(bin_ip[i])
		if (bin_len != 8 ) :
			for j in range (0, 8-bin_len, 1) :
				bin_ip[i] = '0' + bin_ip[i]

	quot = int(int(ip[4]) / 8)
	remain = int(ip[4]) % 8

	print(f'bin_ip : {bin_ip}')

	subnet_mask = []
	subnet_mask_cnt = 0

	for i in range(0, quot) :
		subnet_mask.append(ip[i])
		subnet_mask_cnt += 1

	subnet_mask.append(bin_ip[quot][:remain])

	for i in range(0, 8 - remain) :
		subnet_mask[-1] = subnet_mask[-1] + '0'
	subnet_mask[-1] = '0b' + subnet_mask[-1]

	subnet_mask[-1] = str(int(subnet_mask[-1], 2))


	while (subnet_mask_cnt < 4) :
		subnet_mask.append('0')
		subnet_mask_cnt += 1

	print()
	print(f'subnet mask : {subnet_mask[:4]}')
	print()
	print()
	print()


