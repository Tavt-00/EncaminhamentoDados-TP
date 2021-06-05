'RIP LISBOA' - FUNFANDO
	
-> em routers normais
	-> Em cada router fiz o RIP v2 
		-> ver se é mesmo preciso rip para a 192.168.1.0 e sequer a outra???
	-> meti o passive-interface para cada uma das duas portas que estão ligadas a um pc
	-> a autenticação para cada interface
	-> no auto-summary

-> no router de saida, o R6
	-> meti o 'default-information originate' e meti 'ip route 0.0.0.0 0.0.0.0 Ethernet0/0' (porta para dentro da filial)
	-> meti rip v2 tb mas não meti nenhuma n etwork



'EIGRP PORTO' - FUNFANDO

->em routers normais
	-> fiz router eigrp 1,  networks de cada router e wildcard mask
		-> ATENCAO QUE AQUI AS NETWORKS É 194.65.79.restoRede e não .0
	-> conf t, router eigrp 1, metric weights 0 1 1 1 1 1 
	-> fiz no auto-summary
	-> meti o passive-interface para cada uma das duas portas que estão ligadas a um pc
	-> a autenticação para cada interface

-> no router de saida, R6
	-> fiz router eigrp 1, netword 192.168.1.0 e wildcard mask
	-> fiz autenticação para a e0/0



'EIGRP FARO' - FUNFANDO

->em routers normais
	-> fiz router eigrp 1,  networks de cada router e wildcard mask
		-> ATENCAO QUE AQUI AS NETWORKS É 194.65.79.restoRede e não .0
	-> conf t, router eigrp 1, metric weights 0 1 1 1 1 1 
	-> fiz no auto-summary
	-> meti o passive-interface para cada uma das duas portas que estão ligadas a um pc
	-> a autenticação para cada interface

-> no router de saida, R6
	-> fiz router eigrp 1, netword 192.168.1.0 e wildcard mask
	-> fiz autenticação para a e0/0


'EIGRP FUNCHAL' - FUNFANDO

->em routers normais
	-> fiz router eigrp 1,  networks de cada router e wildcard mask
		-> ATENCAO QUE AQUI AS NETWORKS É 194.65.79.restoRede e não .0
	-> conf t, router eigrp 1, metric weights 0 1 1 1 1 1 
	-> fiz no auto-summary
	-> meti o passive-interface para cada uma das duas portas que estão ligadas a um pc
	-> a autenticação para cada interface

-> no router de saida, R6
	-> fiz router eigrp 1, netword 192.168.1.0 e wildcard mask
	-> fiz autenticação para a e0/1


'IPV6 FUNCHAL'

-> fiz para o router R1, R4, R5 e para 1 pc de cada um desses routers
	-> em cada um tive de fazer: ipv6 unicast-routing 

-> meti ipv6 nos 3 pcs, segundo o que está na topologia

-> meti ipv6(ip de entre routers) nos 3 routers na interface e0/1 

-> meti ipv6 em cada porta que liga o router ao pcs

-> criei 'tunel e encaminhamento dinamico por EIGRP'EIGRP

	-> no R1
		-> conf t, int tunnel 0, ipv6 add 2002:C0A8:0114::1/64, tunnel source 192.168.1.20, tunnel mode ipv6ip 6to4
				-> C0A8:0114 porque é 192(C0) . 168(A8) . 1(01) . 20(14)
		-> conf t, ipv6 route 2002::/16 tunnel 0 
		-> conf t, ipv6 router eigrp 1, redistribute connected, no shut, int e0/1, ipv6 eigrp 1

	-> no R5
		-> conf t, int tunnel 0, ipv6 add 2002:C0A8:0116::1/64, tunnel source 192.168.1.22, tunnel mode ipv6ip 6to4
		-> conf t, ipv6 route 2002::/16 tunnel 0 
		-> conf t, ipv6 router eigrp 1, redistribute connected, no shut, int e0/1, ipv6 eigrp 1

	-> no R6
		-> conf t, int tunnel 0, ipv6 add 2002:C0A8:0115::1/64, tunnel source 192.168.1.21, tunnel mode ipv6ip 6to4
		-> conf t, ipv6 route 2002::/16 tunnel 0 
		-> conf t, ipv6 router eigrp 1, redistribute connected, no shut, int e0/1, ipv6 eigrp 1
 



'OSPF COIMBRA' - FUNFANDO

->em routers normais
	
	-> fiz o router ospf
	-> fiz o identificador de cada router: router-id 9.9.9.nºRouter 
		-> fiz clear ip ospf process a seguir
	-> fiz passive-interface 

-> no router de saida, R10
	-> fiz ospf para a rede 192.168.1.32
	-> fiz o indicador do router dele
	-> fiz autenticação para a A0 apenas

-> em routers sem precisar de VIRTUAL LINKS

	->fiz autenticação para a A0 e a AREA que cada router tem um pc lá ligado

		-> conf t, int e0/1, ip ospf message-digest-key 1 md5 OSPF_A0COIMBRA, router ospf 1, area 0 authentication message-digest 
		-> conf t, int e0/1, ip ospf message-digest-key 1 md5 OSPF_AXCOIMBRA, router ospf 1, area x authentication message-digest 

-> no routers que usam VIRTUAL LINKS
	
	-> no R3
		-> meti  ip ospf message-digest-key 1 md5 OSPF_AXCOIMBRA para a A2 e A0
		-> fiz as area x authentication
		-> fiz virtual link para o router R4 pela area 2

	-> no R4
		-> meti  ip ospf message-digest-key 1 md5 OSPF_AXCOIMBRA para a A1 e A2
		-> fiz as area x authentication tb para a A0
		-> fiz virtual link para o router R3 pela area 2

	-> no R6	
		-> meti  ip ospf message-digest-key 1 md5 OSPF_AXCOIMBRA para a A1 e A0
		-> fiz as area x authentication
		-> fiz virtual link para o router R7 pela area 1

	-> no R7
		-> meti  ip ospf message-digest-key 1 md5 OSPF_AXCOIMBRA para a A1 e A2
		-> fiz as area x authentication tb para a A0
		-> fiz virtual link para o router R6 pela area 1

-> ATENÇÃO QUE NOS ROUTERS QUE LIGAM ÀS FILIAIS NÃO METI NENHUM OSPF MESSAGE-DIGEST PARA NENHUMA AREA NAS INTERFACES QUE LIGAM ÀS FILAIS, SE QUISER PINGAR PARA ELAS TENHO DE METER DEPOIS


'ligação PORTO-COIMBRA' - FUNFANDO

-> no router do porto R6_P 
	
	-> coloquei no EIGRP dele a rede PORTO-COIMBRA
		-> network 10.10.1.4 0.0.0.3 

-> no router de coimbra, R4_C

	-> fiz a redistribuição, criando lá um eigrp também para assim Coimbra falar EIGRP e meti a rede PORTO-COIMBRA
		-> network 10.10.1.4 0.0.0.3 

		-> depois no eigrp 
			-> router eigrp 1, metric weights 0 1 1 1 1 1, network 10.10.1.4 0.0.0.3,  redistribute ospf 1 metric 1000 2000 255 1 1500

		-> e no ospf 
			-> router ospf 1, redistribute eigrp 1 subnets


'ligação PORTO-FARO' - FUNFANDO

-> no eigrp do faro e porto meti
	-> network 10.10.1.8 0.0.0.3

	-> nas interfaces de cada router que se ligam entre routers não meti autenticação


'ligação LISBOA-COIMBRA' 

-> no router do porto R6_L 
	
	-> coloquei no EIGRP dele a rede PORTO-COIMBRA
		-> network 10.10.0.0(rip não olha para as classes) 0.0.0.3 

-> no router de coimbra, R7_C

	-> fiz a redistribuição, criando lá um eigrp também para assim Coimbra falar EIGRP e meti a rede PORTO-COIMBRA
		-> network 10.10.1.0 0.0.0.3 

		-> depois no eigrp 
			-> router rip, version 2, network 10.0.0.0, no auto-summary, redistribute ospf 1 metric 10

		-> e no ospf 
			->   router ospf 1, redistribute rip subnets












			