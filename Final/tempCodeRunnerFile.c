bool chkDigits(char str[10])
{

    bool flag = false;
    int i = 0;
    int j = 0;

    if ((str[0] >= '0' && str[0] <= '9'))
    {

        for (i = 1; i < strlen(str); i++)
        {
            if ((str[i] >= '0' && str[i] <= '9'))
            {
            }
            else if (str[i] == '.')
            {

                for (j = i + 1; j < strlen(str); j++)
                {
                    if ((str[j] >= '0' && str[j] <= '9'))
                    {
                    }
                    else
                    {
                        flag = false;
                    }
                }
                i = j;
            }
            else if (str[i] == 'e' || str[i] == 'E')
            {
                i = i + 1;
                if (str[i] == '+' || str[i] == '-')
                {

                    for (j = i + 1; j < strlen(str); j++)
                    {
                        if ((str[j] >= '0' && str[j] <= '9'))
                        {
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                    i = j;
                }
                else
                {
                    flag = false;
                }
            }
            else
            {
                flag = false;
            }
        }
    }
    else
    {
        flag = false;
        return flag;
    }

    return flag;
}

