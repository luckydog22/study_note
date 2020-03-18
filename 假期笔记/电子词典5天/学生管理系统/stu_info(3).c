#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

#include <sqlite3.h>

/*增加学生信息*/
void do_insert(sqlite3 *db)
{
	int id;
	int age;
	int score;
	char name[64];
	char sql[1024];
	char *errmsg = NULL;
	
	printf("Please input student's info: \n");
	printf("id    name   age   score\n");
	if (4 != scanf("%d%s%d%d", &id, name, &age, &score)) {
		fprintf(stderr, "Insert stu's info error!\n");
		fgets(name, sizeof(name), stdin);
		return;
	}
	getchar();   //把scanf末尾的'\n'吃掉
	
	sprintf(sql, "insert into stu values(%d, '%s', %d, %d)", id, name, age, score);
	if (0 != sqlite3_exec(db, sql, NULL, NULL, &errmsg)) {
		fprintf(stderr, "insert: %s\n", errmsg);
		return;
	}
}

int callback(void *para, int f_num, char **f_value, char **f_name)
{
	int i;
	for (i = 0; i < f_num; i++)
		printf("%-15s", f_value[i]);
	printf("\n");
	return 0;
}

/*查询所有学生的信息*/
void do_query(sqlite3 *db)
{
	char *errmsg = NULL;
	if (0 != sqlite3_exec(db, "select * from stu;", callback, NULL, &errmsg)) {
		fprintf(stderr, "query exec: %s\n", errmsg);
		return;
	}
	
}

/*按名字查询学生的信息---sqlite3_get_table*/
void do_name_query(sqlite3 *db)
{
	char name[64];
	char sql[1024];
	int nrow, ncolumn;
	char **resultp = NULL;
	char *errmsg = NULL;
	int i, j;
	int index;
	
	printf("Please input stu's name: ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name)-1] = '\0';   //'\n'-->'\0'
	
	sprintf(sql, "select * from stu where name = '%s'", name);
	if (0 != sqlite3_get_table(db, sql, &resultp, &nrow, &ncolumn, &errmsg)) {
		fprintf(stderr, "name query failed: %s\n", errmsg);
		return;
	}
	
	if (0 == nrow) {
		printf("No such name! query failed!\n");
		return;
	}
	index = ncolumn;
	for (i = 1; i < nrow+1; i++) {
		for (j = 0; j < ncolumn; j++)
			printf("%-15s", resultp[index++]);
		printf("\n");
	}
}

/*删除学生信息*/
void do_delete(sqlite3 *db)
{
	int id = 0;
	char str[64];
	char sql[1024];
	char *errmsg = NULL;

	printf("Please input delete stu's id: ");
	fgets(str, sizeof(str), stdin);
	id = atoi(str);
	if (0 == id) {
		fprintf(stderr, "Input error, delete failed!\n");
		return;
	}
	sprintf(sql, "delete from stu where id=%d", id);
	if (0 != sqlite3_exec(db, sql, NULL, NULL, &errmsg)) {
		fprintf(stderr, "sqlite3_exec delete: %s\n", errmsg);
		return;
	}
}

/*更新学生信息*/
void do_update(sqlite3 *db)
{
	int id = 0;
	int age, score;
	char name[64];
	char str[64];
	char sql[1024];
	char *errmsg = NULL;

	printf("Please input update stu's id: ");
	fgets(str, sizeof(str), stdin);
	id = atoi(str);
	if (0 == id) {
		fprintf(stderr, "Input id error, update failed!\n");
		return;
	}
	printf("Please input after update stu's info: \n");
	printf("name    age    score\n");
	if (3 != scanf("%s%d%d", name, &age, &score)) {
		fprintf(stderr, "Input stu's info error, update failed!\n");
		fgets(str, sizeof(str), stdin);
		return;
	}
	getchar();
	
	sprintf(sql, "update stu set name='%s',age=%d,score=%d where id=%d", name, age, score, id);
	if (0 != sqlite3_exec(db, sql, NULL, NULL, &errmsg)) {
		fprintf(stderr, "update exec: %s\n", errmsg);
		return;
	}
}

int main(int argc, char *argv[])
{
	char order[64];
	sqlite3 *db = NULL;
	char *errmsg = NULL;
	
	/*创建并打开数据库*/
	if (0 != sqlite3_open("stu_info.db", &db)) {
		fprintf(stderr, "sqlite3_open: %s\n", sqlite3_errmsg(db));
		return -1;
	} 

	/*创建学生信息表*/
	if (0 != sqlite3_exec(db, "create table if not exists stu(id integer primary key, name text, age integer, score integer)", NULL, NULL, &errmsg)) {
		fprintf(stderr, "sqlite3_exec: %s\n", errmsg);
		return -1;
	}

	while (1) {
		printf("*******************************************\n");
		printf("		1. 查询所有学生的信息 \n");
		printf("		2. 按名字查询学生信息 \n");
		printf("		3. 增加学生的信息 \n");
		printf("		4. 删除学生的信息 \n");
		printf("		5. 修改学生的信息 \n");
		printf("		6. 退出系统 \n");
		printf("*********输入想要选择功能的数字(1-6)***********\n");
#if 0
		if (1 != scanf("%d", &order)) {  //成功输入order , int order;
			fgets(buf, sizeof(buf), stdin);
			fprintf(stderr, "Input error, Again!\n");
			continue;
		}
		getchar();
#else
		fgets(order, sizeof(order), stdin);
		
		switch (order[0]) {
			case '1':
				do_query(db);
				break;
			case '2':
				do_name_query(db);
				break;
			case '3':
				do_insert(db);
				break;
			case '4':
				do_delete(db);
				break;
			case '5':
				do_update(db);
				break;
			case '6':
				sqlite3_close(db);
				exit(0);
				break;
			default:
				fprintf(stderr, "Input error, again!\n");
				break;
			
		}
#endif
	}

	return 0;
}
