'RIP LISBOA'
	
-> em routers normais
	-> Em cada router fiz o RIP v2 
		-> ver se é mesmo preciso rip para a 192.168.1.0 e sequer a outra???
	-> meti o passive-interface para cada uma das duas portas que estão ligadas a um pc
	-> a autenticação para cada interface
	-> no auto-summary

-> no router de saida, o R6
	-> meti o 'default-information originate' e meti 'ip route 0.0.0.0 0.0.0.0 Ethernet0/0' (porta para dentro da filial)
	-> meti rip v2 tb mas não meti nenhuma network


PARECE ESTAR A FUNFAR

'EIGRP PORTO'

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



'OSPF COIMBRA'

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