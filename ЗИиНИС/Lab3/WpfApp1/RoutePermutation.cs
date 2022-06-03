namespace WpfApp1
{
    internal class RoutePermutation
    {
        #region setters
        static string firstText { get; set; }
        #endregion

        internal static string Encrypt(string textToEncrypt, string key)
        {
            string DecryptedText = "";
            firstText = key;
            string text = key + textToEncrypt;
            char[,] tabl = new char[key.Length, text.Length / key.Length];

            int k = 0;
            for (int i = 0; i < key.Length; i++)
            {
                for (int j = 0; j < text.Length / key.Length; j++)
                {
                    tabl[i, j] += text[k++];
                }
            }

            for (int i = 0; i <= (text.Length / key.Length) - 1; i++)
            {
                if (i == 0 || i % 2 == 0)
                {
                    for (int j = key.Length - 1; j >= 0; j--)
                    {
                        DecryptedText += tabl[j, i];
                    }
                }
                else
                {
                    for (int j = 0; j <= key.Length - 1; j++)
                    {
                        DecryptedText += tabl[j, i];
                    }
                }
            }

            return DecryptedText;
        }

        internal static string Decrypt(string textToDecrypt, string key)
        {
            char[,] tabl = new char[key.Length, textToDecrypt.Length / key.Length];

            int k = 0;
            for (int i = 0; i < key.Length; i++)
            {
                for (int j = 0; j < textToDecrypt.Length / key.Length; j++)
                {
                    tabl[i, j] += textToDecrypt[k++];
                }
            }

            string firsttext = "";
            for (int i = (textToDecrypt.Length / key.Length) - 1; i >= 0; i--)
            {
                if (i == 0 || i % 2 == 0)
                {
                    for (int j = key.Length - 1; j >= 0; j--)
                    {
                        firsttext += tabl[j, i];
                    }
                }
                else
                {
                    for (int j = 0; j <= key.Length - 1; j++)
                    {
                        firsttext += tabl[j, i];
                    }
                }
            }
            return firstText;
        }
    }
}
