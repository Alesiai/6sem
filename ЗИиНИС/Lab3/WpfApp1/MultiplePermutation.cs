using System.Collections.Generic;
using System.Linq;

namespace WpfApp1
{
    internal class MultiplePermutation
    {
        internal static string firstKey = "Alesia";
        internal static string secondKey = "Ivanova";
        internal static List<CharNum> listCharNumFirst;
        internal static List<CharNum> listCharNumSecond;


        internal static string Encrypt(string textToEncrypt)
        {
            string fill = " ";

            for (int i = textToEncrypt.Length; i < firstKey.Length * secondKey.Length; i++)
            {
                textToEncrypt += fill;
            }
            string encryptedText = "";
            // Матрица в которой производим шифрование
            char[,] matrix = new char[secondKey.Length, firstKey.Length];

            // Счетчик символов в строке
            int countSymbols = 0;

            // Переводим строки в массивы типа char
            char[] charsFirstKey = firstKey.ToCharArray();
            char[] charsSecondKey = secondKey.ToCharArray();
            char[] charStringUser = textToEncrypt.ToCharArray();

            // Создаем списки в которых будут храниться символы и порядковые номера символов
            listCharNumFirst =
                new List<CharNum>(firstKey.Length);

            listCharNumSecond =
                new List<CharNum>(secondKey.Length);

            // Заполняем символами из ключей
            listCharNumFirst = FillListKey(charsFirstKey);
            listCharNumSecond = FillListKey(charsSecondKey);

            // Заполняем порядковыми номерами
            listCharNumFirst = FillingSerialsNumber(listCharNumFirst);
            listCharNumSecond = FillingSerialsNumber(listCharNumSecond);

            // Заполнение матрицы строкой пользователя
            for (int i = 0; i < listCharNumSecond.Count; i++)
            {
                for (int j = 0; j < listCharNumFirst.Count; j++)
                {
                    matrix[i, j] = charStringUser[countSymbols++];
                }
            }


            countSymbols = 0;
            // Заполнение матрицы с учетом шифрования. 
            // Переставляем столбцы по порядку следования в первом ключе. 
            // Затем переставляем строки по порядку следования во втором ключа. 
            for (int i = 0; i < listCharNumSecond.Count; i++)
            {
                for (int j = 0; j < listCharNumFirst.Count; j++)
                {
                    matrix[listCharNumSecond[i].NumberInWord,
                       listCharNumFirst[j].NumberInWord] = charStringUser[countSymbols++];
                }
            }

            for (int i = 0; i < listCharNumFirst.Count; i++)
            {
                for (int j = 0; j < listCharNumSecond.Count; j++)
                {
                    encryptedText += matrix[j, i];
                }
            }

            return encryptedText;
        }

        /// <summary>
        /// Заполнение символов ключей, порядковыми номерами.
        /// </summary>
        /// <param name="listCharNum"></param>
        /// <returns></returns>
        private static List<CharNum> FillingSerialsNumber(List<CharNum> listCharNum)
        {
            int count = 0;

            var result = listCharNum.OrderBy(a =>
                a.NumberInWord);

            foreach (var i in result)
            {
                i.NumberInWord = count++;
            }

            return listCharNum;
        }

        /// <summary>
        /// Заполнение символами списка с ключом.
        /// </summary>
        /// <param name="chars">массив символов.</param>
        /// <returns>Список символов.</returns>
        private static List<CharNum> FillListKey(char[] chars)
        {
            List<CharNum> listKey = new List<CharNum>(chars.Length);

            for (int i = 0; i < chars.Length; i++)
            {
                CharNum charNum = new CharNum()
                {
                    Ch = chars[i],
                    NumberInWord = MainWindow.GetNumberInThealphabet(chars[i])
                };

                listKey.Add(charNum);
            }
            return listKey;
        }

        internal static string Decrypt(string textToEncrypt)
        {
            char[,] newMatrix = new char[secondKey.Length, firstKey.Length];
            List<int> list1 = new List<int>();
            List<int> list2 = new List<int>();
            foreach (CharNum index in listCharNumFirst)
            {
                list1.Add(index.NumberInWord);
            }
            foreach (CharNum index in listCharNumSecond)
            {
                list2.Add(index.NumberInWord);
            }
            int k = 0;

            for (int i = 0; i < firstKey.Length; i++)
            {
                int x = list1.IndexOf(i);
                for (int j = 0; j < secondKey.Length; j++)
                {
                    int y = list2.IndexOf(j);
                    newMatrix[y, x] = textToEncrypt[k];
                    k++;
                }
            }

            string decryptedText = "";

            for (int i = 0; i < secondKey.Length; i++)
            {
                for (int j = 0; j < firstKey.Length; j++)
                {
                    decryptedText += newMatrix[i, j];
                }
            }

            return decryptedText;
        }
    }
}
