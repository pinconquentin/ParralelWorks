int main () {
int toto ;
 int zbla ;
 zbla = 3;
 toto = 6;
 zbla = zbla + toto ;

 while (toto > zbla) {
 	while (zbla == toto) {
 		toto = toto - 1;
 		if (toto < zbla ) {
 			toto = toto + 10;
 		}
 		else {
 			zbla = 25;
 		}
 	}
 	zbla = zbla + 1 ;
 }
return 0;
}