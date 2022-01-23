# get_next_line
파일 디스크립터로부터 읽혀진개행으로 끝나는 한 줄을 반환하는 함수를 코드화 하는 것입니다.

## read 함수

### ssize_t read(int fd, void *buf, size_t len)
fd가 참조하는 파일의 현재 offset에서 len바이트만큼 buf로 읽어들인다.   
읽어들이는 작업 성공시 buf에 쓴 바이트 숫자 반환, 읽어들이는 작업 실패시 -1을 반환한다.   
offset은 fd에서 읽은 바이트크기(len) 만큼 앞으로 나아간다.   
