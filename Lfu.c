#include <stdio.h>

#define MAX 100

typedef struct {
    int page;
    int freq;
    int time;
} Frame;
int search(Frame frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i].page == page)
            return i;
    }
    return -1;
}
int findLFU(Frame frames[], int n) {
    int minFreq = frames[0].freq;
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (frames[i].freq < minFreq) {
            minFreq = frames[i].freq;
            pos = i;
        }
        else if (frames[i].freq == minFreq) {
            if (frames[i].time < frames[pos].time)
                pos = i;
        }
    }
    return pos;
}
int main() {
    int pages[MAX], n, framesCount;
    printf("Enter number of pages :");
    scanf("%d", &n);
    printf("Enter page reference string : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &framesCount);
    Frame frames[framesCount];
    for (int i = 0; i < framesCount; i++) {
        frames[i].page = -1;
        frames[i].freq = 0;
        frames[i].time = 0;
    }
    int pageFaults = 0, timer = 0;

    for (int i = 0; i < n; i++) {
        int pos = search(frames, framesCount, pages[i]);
        if (pos != -1) {
            frames[pos].freq++;
            frames[pos].time = ++timer;
        } else {
            int replace = findLFU(frames, framesCount);

            for (int j = 0; j < framesCount; j++) {
                if (frames[j].page == -1) {
                    replace = j;
                    break;
                }
            }
            frames[replace].page = pages[i];
            frames[replace].freq = 1;
            frames[replace].time = ++timer;
            pageFaults++;
        }
        printf("Frames: ");
        for (int j = 0; j < framesCount; j++) {
            if (frames[j].page != -1)
                printf("%d,", frames[j].page);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("Total Page Faults = %d\n", pageFaults);
    return 0;
}





