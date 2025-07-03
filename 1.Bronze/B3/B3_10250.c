#include <stdio.h>

int main(){
    int floor, room, guest;
    int loop;
    int room_num;
    
    scanf("%d", &loop);

    for(int i = 0; i < loop; i++){
        room_num = 0;
        scanf("%d %d %d", &floor, &room, &guest);
        room_num += (guest%floor != 0) ? (guest%floor)*100 : floor*100;
        room_num += (guest%floor != 0) ? (guest/floor) + 1 : (guest/floor);
        printf("%d\n", room_num);
    }

    return 0;
}