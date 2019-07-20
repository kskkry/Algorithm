
//挿入ソート
void insertion_sort(int a[],int n){
    for(int i = 0; i < n; i++){
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
}



//バブルソート
void bubblesort(int a[],int n){
    bool flg = 1;
    while(flg){
        flg = 0;
        for(int i = n-1; i >= 1; i--){
            if (a[i] < a[i-1]){
                //a[i]とa[i-1]を入れ替え
                int tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                flg = 1;
            }
        }
    }
}

//選択ソート
void selectionsort(int a[],int n){
    for(int i = 0; i < n; i++){
        int mn = i;

        //各区間で最小値を更新
        for(int j = i; j < i-1; j++){
            if (a[j] < a[mn]){
                mn = j;
            }
        }
        //最小値を交換（）
        int tmp = a[i];
        a[i] = a[mn];
        a[mn] = a[i];
    }
}


//挿入ソート(未完成)
void shellsort(int a[],int n,int g){
    for(int i = g; i < n; i++){
        int v = a[i];
        int j = i-g;
        while(j >= 0 && a[j] > v){
            a[j+g] = a[j];
            j = j - g;
            //cnt++;
        }
    }
}

//シェルソート(未完成)
void shellsort(int a[],int n){
    int cnt = 0;
    int m = -1e9;
}


//計数ソート
void counting_sort(int a[],int b[],int k){
    //値の範囲が0からk
    int c[k];
    for(int i = 0; i < k; i++){
        c[i] = 0;
    }

    //要素数n
    int n;

    //indexの番号を間違えやすいので注意
    for(int i = 0; i < n; i++){
        c[a[i]]++;
    }
    for(int i = 0; i < k; i++){
        c[i] = c[i]+c[i-1];
    }
    for(int i = n-1; i >= 1; i--){
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
}
