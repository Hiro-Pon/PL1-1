 #include <stdio.h>

int main(void){
  FILE * fp = fopen("text_copy.txt","r"); // text_copy.txt

  /* ファイルサイズを取得する */
  fseek(fp, 0, SEEK_END);
  int filesize = ftell(fp);
  /* ファイルポインタを先頭に戻す */
  fseek(fp, 0, SEEK_SET);

  printf("File size = %d\n", filesize);

  fclose(fp);
}
