int ans =0;
long sum=0;
for ( int i=0;i<n-2;i++){
    sum+=arr[i];
    for (int j = i+1;j<n-1;j++){
        
        for (int k = j+1;k<n;k++){
            long sum = arr[i]+arr[j]+arr[k];
            if (sum%d==0)ans++;
        }
    }
}