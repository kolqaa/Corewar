.name "zo#rk"
.comment "just a basic living prog"
	
lable:  sti 	r1,%:live,r2 
	and	r1,%0,r1

simple_lable:	
live:	live	%2
	zjmp	%:live
	
	