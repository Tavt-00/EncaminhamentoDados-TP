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

-> discar routes
	-> fiz discard routes porque meti para não sumarizar

	-> ip route 194.65.78.0 255.255.255.0 null0
	-> ip route 194.65.78.0 255.255.255.0 null0
	-> ip route 192.168.1.0 255.255.255.0 null0


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

-> discar routes
	-> fiz discard routes porque meti para não sumarizar

	-> ip route 194.65.78.0 255.255.255.0 null0
	-> ip route 194.65.78.0 255.255.255.0 null0
	-> ip route 192.168.1.0 255.255.255.0 null0


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

-> discar routes
	-> fiz discard routes porque meti para não sumarizar

	-> ip route 194.65.78.0 255.255.255.0 null0
	-> ip route 194.65.78.0 255.255.255.0 null0
	-> ip route 192.168.1.0 255.255.255.0 null0


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

-> discar routes
	-> fiz discard routes porque meti para não sumarizar

	-> ip route 194.65.78.0 255.255.255.0 null0
	-> ip route 194.65.78.0 255.255.255.0 null0
	-> ip route 192.168.1.0 255.255.255.0 null0


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

	-> no R8
		-> meti uma area stub 
			-> conf t, router ospf 1, area 1 stub -> EXPLICAR DEPOIS NO RELATÓRIO O QUE QUER DIZER ESSE STUB LÁ 


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

-> 'ligação FUNCHAL-FARO' - FUNFANDO

-> no eigrp de faro e funchal meti 
	-> network 10.10.1.12 0.0.0.3


-> 'ligação FUNCHAL-LISBOA' - ??????



'ligação LISBOA-COIMBRA' - FUNFANDO

-> coloquei o RIP também em lisboa, para ele conseguir receber o de funchal

	-> criei entao o eigrp 1 em lisboa com o metric weights 
	-> meti a network 10.10.1.16 
	-> fiz redistribute rip metric 1000 2000 255 1 1500, redistribuindo dentro do eigrp o rip

	-> no rip redistribui o eigrp com uma metrica mais pequena para de lisboa para funchal ir logo por aí 

-> no router de saida do funchal, R6, meti no EIGRP dele a network 10.10.1.16 



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


-> uma interface de loopback, para que se possa testar a conectividade com a organização (ip 2.2.2.2)
	-> conf t ... int loopback0 ... ip add 2.2.2.2 255.255.255.255, no shut


-> Todos os routers devem permitir o acesso remoto por telnet a apenas uma sessão com a password “cisco”

	-> para encriptar
		-> conf t, service password-encryption 

	-> para o telnet
		-> fiz enable secret cisco para ter de meter pass quando faz telnet

		-> line vty 1(porque era só uma sessão), password cisco, login, transport intput telnet


-> o que fiz para a 'saída PRIMÁRIA'

	-> no RISP
		-> meti a rota 194.65.78.0/24 is directly connected, Serial2/0
		-> metia rota  194.65.79.0/24 is directly connected, Serial2/0


	-> no R10_C
		-> meti a rota ip route 0.0.0.0 0.0.0.0 Serial2/0
		-> meti no OSPF o default-information originate metric type 1 para saberem que é o router de saída de Coimbra

-> o que fiz para a 'saída SECUNDÁRIA'

	-> no RISP 
		-> meti a rota ip route 194.65.78.0 255.255.255.0 s2/1 2 com metrica 2 para ter um salto maior e assim se tornar secundária
		-> meti a rota ip route 194.65.79.0 255.255.255.0 s2/1 2, este 2 significa o mesmo que em cima

	-> no R7_C
		-> como este router está ligada a lisboa e como lisboa tem a ligação SECUNDÁRIA tive de dizer que caso a PRIMÁRIA esteja down, ou seja, algo se passe por exemplo no R10_C	
			então é o R7_C que vai ser a saída (para se usar a SECUNDÁRIA)

			-> então meti no R7_C um default-information originate no OSPF 

	-> no R6_L 
		-> fiz um default route direcionado para a ligação secundária para assim estabelecer a mesma
		-> tive de lhe meter um métrica maior que a do RIP visto que é este o protocolo que está lá a funfar e não se sobrepor
		-> meti assim um 121 visto que o RIP é de 120

			->  ip route 0.0.0.0 0.0.0.0 10.10.89.225 121 


-> Fazer a prefix-list por forma a impedir que um router receba alguns anuncios RIP
	
	-> fiz no R3 de lisboa

	-> neguei para a rede publica de lisboa, a 194.65.78.160
		-> ip prefix-list NO_RIPR3 seq 5 deny 194.65.78.160/29  

	-> temos de permitir as outras todas, le porque lower ou equal, máscara tem de ser menor ou igual que 32, ou seja, qq uma
		-> ip prefix-list NO_RIPR3 seq 10 permit 0.0.0.0/0 le 32


-> uma ligação secundária de 50 Mbps a partir de Lisboa
	
	-> no R6_L, router de saída de lisboa
		-> conf t, int s2/2, bandwidth 50000

-> A sede encontra-se ligada à Internet através de uma ligação primária de 1 Gbps

	-> no router R10_C, no que está ligado ao RISP
		->  conf t, int s2/0, bandwidth 50000 

-> As filiais estão ligadas entre si e com a sede através de ligações de 100 Mbps
	-> fiz para o router R7_C e R4_C e ainda para o de saida de lisboa, porto e faro para as ligações entre filiais nas respetivas portas que fazem as respetivas ligações


-> meti no Router R7_C, router de coimbra que liga a lisboa 
	->  router ospf 1, distance 50 192.168.1.0 0.0.0.7

	-> para assim ir logo para lisboa quando pingamos o 1.1.1.1 por exemplo do funchal e não ir por uma volta ao bilhar grandes 