#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nblinerecover(){
	FILE *f = fopen("/var/log/auth.log" , "r");
	int nb=0;
	char *linerecover = (char*)malloc(sizeof(char)*600);
	while(!feof(f)){
		fgets(linerecover,255,f);
		nb++;
	}
	fclose(f);
	return nb-100;
}

int main(){
	printf("Content-type: text/html\n\n");
	printf("<head><meta charset=\"UTF-8\"><title>LogAuth</title>\n");
	printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
	
	printf("<style>");
	printf("body{width:80%%;text-align:center;justify-content:center;background:-moz-linear-gradient(top right,yellow,red);width:80%%;}");
	printf("table{width:80%%;margin:0 0%% 0 20%%;border:2px solid rgb(91, 127, 204);}");
	char a[2]="@";
	printf("tbody{color: rgba(217, 245, 247, 0.959);background-color: rgb(19, 44, 155);}");
	printf("thead{width:80%%;color:rgb(224, 223, 241);border:1px solid white;background: linear-gradient(90deg, rgba(224, 19, 29, 0.993), rgba(55, 15, 233, 0.493));}");
	printf("tr{padding:1%% 2%% 1%% 2%%;}");
	printf("td,th{padding:0%% 2%% 0 2%%;text-align:center;}");
	printf("%smedia screen and (max-width:900px){tbody,thead{background-color:green;font-size:80%%;}td{padding:1%% 3%% 1%% 3%%}thead,th{width: 40%%;padding:1%% 2%% 1%% 2%%;}}",a);
	printf("%smedia screen and (max-width:600px){tbody,thead{font-size:65%%;}td{padding:1%% 3%% 1%% 3%%}thead,th{width: 40%%;padding:1%% 2%% 1%% 2%%;}body{background:linear-gradient(95deg,yellow,red);}}",a);	
	printf("</style>");

	printf("</head>\n");
	printf("<html><body><h1>Les 100 dernieres Authentification réussites</h1>");
	printf("<center><table border = \"1\">"); 
	printf("<tr><thead><th>Temps</th>");
	printf("<th>Session d'Ouverture/Fermeture</th>");
	printf("<th>Utilisateur</th></thead></tr>");
	char *linerecover = (char*)malloc(sizeof(char)*600);
	int compt=0;
	char* month = (char*)malloc(sizeof(char)*6);
	int day=0;
	char *hours = (char*)malloc(sizeof(char)*20);
	char *session = (char*)malloc(sizeof(char)*40);
	char* other = (char*)malloc(sizeof(char)*155);
	int lineBeginRecover = nblinerecover();
	
	FILE *file = fopen("/var/log/auth.log" , "r");
	int m=1;
	while(!feof(file)){
		fgets(linerecover,255,file);
		compt++;
		if(strstr(linerecover,"opened")!=NULL || strstr(linerecover,"closed")!=NULL){
			sscanf(linerecover,"%[^ ] %d %[^ ] %*[^ ] %*[^ ] %*[^ ] %*[^ ] %[^ ] %*[^ ] %*[^ ] %[^ ] ",month,&day,hours,session,other);
		}
		if(compt>lineBeginRecover){
			
			printf("<tbody>");
			if(strstr(session,"opened")!=NULL){
				printf("<tr style=\"background:orange;\"><td>%s %d %s</td>",month,day,hours);
			}
			else{
				printf("<tr><td>%s %d %s</td>",month,day,hours);
			}
			printf("<td>%s</td>",session);
				printf("<td>%s</td></tr>",other);
			m++;
			printf("</tbody>");
		}
	}
	printf("</table></center></body></html>\n\n"); 
	
	fclose(file);
	return 0;
}
