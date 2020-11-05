
int CheckBST(ALBERO *T,int x,int y){

	int A,B,CX=x,CY=y,NX,NY,temp,RET,VAL;
	ALBERO *CT=T,*LT=NULL;
	StackV SX=NULL,SY=NULL,SA=NULL,SVAL=NULL;
	Stack ST=NULL;
	
	while(CT || ST){
		A=1;
		B=1;
		while(CT !=NULL || ST !=NULL){
			
			// inizio il ciclo e arrivo alla prima ricorsione
			if(CT){
				VAL=*(int*)CT->Nome;
				printf("\n|Il risultato e' :'%d|\n",VAL);
				if(CX<=VAL && VAL<=CY){
					ST=Push(ST,CT);
					SX=PushV(SX,(void*)CX);
					SY=PushV(SY,(void*)CY);
					SVAL=PushV(SVAL,(void*)VAL);
					CT=CT->Left;
					CX=CX;
					CY=VAL--;
					printf("Finito primo if discesa \n");
				}
				else{
					A=0;
					RET=0;
					LT=CT;
					CT=NULL;
					printf("Finito secondo if discesa \n");
				}
			}
			//Ho aggiornato tutto e sono pronto per il prossimo nodo
			
			else{//sono tra le due ricorsioni e recupero i dati
				CT=Top(ST);
				CX=*(int*)TopV(SX);
				CY=*(int*)TopV(SY);
				VAL=*(int*)TopV(SVAL);
				printf("Ho ricaricato la roba \n");
				if(CT->Right)printf("Ho qualcosa a destra\n");
				else printf("Non Ho qualcosa a destra\n");
				// vedo se posso andare a destra e se ci sono già stato 
				if(CT->Right && CT->Right != LT){
					printf("Sono nel if generale della seconda ricorsione \n");
					A=RET;
					printf("Mi e tornata una A =%d \n",A);
					if(A != 0){
						SA=PushV(SA,(void*)A);
						CT=CT->Right;
						CX=VAL++;
						CY=CY;
					}	
					else{
						RET=A&&B;
						
						ST=Pop(ST);
						SX=PopV(SX);
						SY=PopV(SY);
						SVAL=PopV(SVAL);
	
						LT=CT;
						CT=NULL;
					}
				}
				// Risalgo  
				else{
					printf("Sono nella risalita \n");
					// sono risalito da destra
					if(CT->Right){
						printf("Risalgo da destra \n");
						B=RET;
						printf("Mi e tornata una B = %d \n",B);
						A=(int*)TopV(SA);
						SA=PopV(SA);
						RET=A&&B;						
					}
					// Se non avevo figli era caso base
					else{
						printf("Non avevo figli \n");
						RET=1;
					}
					// Aggiorno gli stack e forzo la risalita
					ST=Pop(ST);
					SX=PopV(SX);
					SY=PopV(SY);
					SVAL=PopV(SVAL);
					
					LT=CT;
					CT=NULL;
					
				}				
			}
			
		}
	}
	printf("Il ritorno e' %d \n",RET);
	return RET;
}
*/