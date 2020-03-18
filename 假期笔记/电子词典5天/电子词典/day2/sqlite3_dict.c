#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <sqlite3.h>

int main()
{
	sqlite3 *db = NULL;
	char *errmsg = NULL;
	FILE *fp = NULL;
	char buf[1024];
	char word[64];
	char explain[256];
	char sql[1024];
	
	if (0 != sqlite3_open("dict.db", &db)) {
		fprintf(stderr, "sqlite3_open: %s\n", sqlite3_errmsg(db));
		return -1;
	}

	if (0 != sqlite3_exec(db, "create table if not exists dict(word text, explain text)", NULL, NULL, &errmsg)) {
		fprintf(stderr, "sqlite3 create dict: %s\n", errmsg);
		return -1;
	}

	if (NULL == (fp = fopen("dict.txt", "r"))) {
		perror("fopen");
		sqlite3_close(db);
		return;
	}

	while (1) {
		//读取文件中的一行内容，当读到文件末尾时跳出循环
		if (NULL == fgets(buf, sizeof(buf), fp)) {  
			break;
		}

		char *p = buf;
		int i = 0;
		//把这一行空格前的内容写入word
		while (' ' != *p) {
			word[i] = *p;
			i++;
			p++;
		}	
		word[i] = '\0';	

		//跳过中间所有的空格
		while (' ' == *p)
			p++;
		//把空格后的内容写入explain
		strcpy(explain, p);
		//把每一行的结束符"\r\n"去掉
		explain[strlen(explain)-2] = '\0';

		sprintf(sql, "insert into dict values('%s', '%s')", word, explain);
		puts(sql);
		if (0 != sqlite3_exec(db, sql, NULL, NULL, &errmsg)) {
			fprintf(stderr, "insert word: %s\n", errmsg);
			break;
		}
	}

	fclose(fp);
	sqlite3_close(db);

	return 0;
}
