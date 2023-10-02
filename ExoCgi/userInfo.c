#include <stdio.h>
#include <stdlib.h>


int main(){
	printf("Content-type: text/html\n\n");
	printf("<html>");
	printf("<head><meta charset=\"UTF-8\"><title>Human users</title></head>\n");
	printf("<style>");
	printf("body{width:80%%;text-align:center;justify-content:center;background:linear-gradient(70deg,yellow,red);width:80%%;}");
	printf("table{width:80%%;margin:0 0%% 0 20%%;border:2px solid rgb(91, 127, 204);}");
	char a[2]="@";
	//printf()
	printf("tbody{color: rgba(217, 245, 247, 0.959);background-color: rgb(19, 44, 155);}");
	printf("thead{width:80%%;color:rgb(224, 223, 241);border:1px solid white;background: linear-gradient(90deg, rgba(224, 19, 29, 0.993), rgba(55, 15, 233, 0.493));}");
	printf("tr{padding:1%% 2%% 1%% 2%%;}");
	printf("td,th{padding:0%% 2%% 0 2%%;text-align:center;}");
	printf("%smedia screen and (max-width:900px){tbody,thead{background-color:green;font-size:80%%;}td{padding:1%% 3%% 1%% 3%%}thead,th{width: 40%%;padding:1%% 2%% 1%% 2%%;}}",a);
	printf("%smedia screen and (max-width:600px){tbody,thead{font-size:65%%;}td{padding:1%% 3%% 1%% 3%%}thead,th{width: 40%%;padding:1%% 2%% 1%% 2%%;}body{background:linear-gradient(95deg,yellow,red);}}",a);	
    printf("</style>");
	printf("<body>");
	char *recuperateur = (char*)malloc(sizeof(char)*255);
	char *userName = (char*)malloc(sizeof(char)*100);
	char *userDirectory = (char*)malloc(sizeof(char)*120);
	int userPid = 0, userGid = 0;
	int compteurUser = 0;
	FILE *file = fopen("/etc/passwd","r");
	
	printf("<h1 style=\"text-align:center;\">Les utilisateurs vivants</h1>");
	printf("<table border = \"1\">"); 
	printf("<tr><th>Nom de l'Utilisateur</th>");
	printf("<th>PID l'Utilisateur</th>");
	printf("<th>GID de l'Utilisateur</th>");
	printf("<th>Repertoire Courant de l'Utilisateur</th></tr>");
	
	while(!feof(file)){
		if(!feof(file)){
			if(userPid>=1000 && userPid<=2000){
				printf("<tr><td>%s</td>",userName);
				printf("<td>%d</td>",userPid);
				printf("<td>%d</td>",userGid);
				printf("<td>%s</td></tr>",userDirectory);
			}
			fgets(recuperateur, 255, file);
			sscanf(recuperateur,"%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%*[^:]:",userName,&userPid,&userGid,userDirectory);
			compteurUser++;
			 
		}
	}
    printf("</body></html>\n\n"); 
	return 0;
}
