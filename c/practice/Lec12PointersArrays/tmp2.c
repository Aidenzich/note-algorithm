//Your code goes here
int *report_card (int *s) {
    int lable[10001] = {0}, continuous = 0;
    int tags = 0;  //頭尾標籤編號
    int length[10001] = {0};
    for (int i = 0; s[i] != -1; i++) {
        if (s[i] >= 60) {
            if (lable[tags] == 0) {  //if Lable head is empty
                lable[tags] = i;     //add i site to No.tags Lable head
                continuous++; 
            } 
            else {
                continuous++;        //if Lable head is existed, continuous++
            }
        }
        else if (s[i] < 60 && lable[tags] != 0)  {    //failed and Lable head is existed
            tags++;            //tags is Lable tail
            s[i] = -1;      //Lable tail site value is -1
            lable[tags] = i;   //add i site to No.tags Lable tail
            length[tags/2] = continuous;  //store the length of tags/2
            continuous = 0;
            tags++;        //Lable tail turn to Lable head, which is empty
        }
    }
    tags++;         //Lable head turn to Lable tail
    length[tags/2] = continuous;  //store the length of tags/2

    int max = 0;    //initiallize the length[0] is max
    int max_sum = 0, k_sum = 0;
    int site = 0;
    //compare length
    for (int k = max + 1; k <= tags/2; k++) { 
        if (length[max] < length[k]) {
            max = k;
        }
        else if (length[max] == length[k]) {
            site = lable[max*2];
            for (int i = 0; i < length[max]; i++) 
                max_sum += s[site++];
            site = lable[k*2];
            for (int i = 0; i < length[k]; i++)
                k_sum += s[site++];
            if (max_sum < k_sum)
                max = k;
        }
    }
    //No.max length is the longest part or bigest part
    int best_site = lable[max*2];;
    return &s[best_site];
}