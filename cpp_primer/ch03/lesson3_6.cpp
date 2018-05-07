int main()
{
    int arr[5][5] = { 0 };
    for (decltype(arr[0]) row : arr)
    {
        for (auto col : row)
        {

        }
    }
    return 0;
}