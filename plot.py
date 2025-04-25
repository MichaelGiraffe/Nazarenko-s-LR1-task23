import pandas as pd
import matplotlib.pyplot as plt
import os


def main():
    try:
        file_path = "timing_results.csv"

        # Проверка существования и размера файла
        if not os.path.exists(file_path):
            raise FileNotFoundError(f"Файл {file_path} не существует")
        if os.path.getsize(file_path) == 0:
            raise ValueError("Файл существует, но пуст")

        # Чтение с автоматическим определением кодировки
        with open(file_path, 'rb') as f:
            rawdata = f.read()
            encoding = 'utf-8'  # По умолчанию
            try:
                rawdata.decode('utf-8').encode('utf-8')
            except UnicodeError:
                encoding = 'cp1251'

        df = pd.read_csv(file_path, sep=';', encoding=encoding)

        # Проверка данных
        if df.empty:
            raise ValueError("Файл не содержит данных")

        print("\nУспешно загружены данные:")
        print(df.head())

        # Построение графика
        plt.figure(figsize=(10, 5))
        plt.plot(df.iloc[:, 0], df.iloc[:, 1], 'bo-')  # Берем первые 2 столбца

        plt.xlabel("Размер данных")
        plt.ylabel("Время (мкс)")
        plt.title("Производительность алгоритма")
        plt.grid(True)

        plt.savefig('performance.png')
        print("\nГрафик сохранен как performance.png")

    except Exception as e:
        print(f"\nОшибка: {str(e)}")
        print("Рекомендации:")
        print("1. Убедитесь, что C++ программа создала файл")
        print("2. Проверьте содержимое файла в блокноте")
        print("3. Запустите C++ программу отдельно и проверьте файл")


if __name__ == "__main__":
    main()