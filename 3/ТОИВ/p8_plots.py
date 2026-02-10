import csv
from datetime import datetime
import matplotlib.pyplot as plt

def load_csv(filename):
    data = {'timestamp': [], 'motion': [], 'temperature': [], 'voltage': []}
    with open(filename, 'r', encoding='utf-8') as f:
        reader = csv.DictReader(f)
        for row in reader:
            data['timestamp'].append(datetime.fromisoformat(row['timestamp']))
            data['motion'].append(int(row['motion']))
            data['temperature'].append(float(row['temperature']))
            data['voltage'].append(float(row['voltage']))
    return data

def main():
    data = load_csv('sensor_data.csv')

    # === 1. Линейный график — температура ===
    plt.figure(figsize=(12, 4))
    plt.subplot(1, 3, 1)
    plt.plot(data['timestamp'], data['temperature'], color='red', marker='o', markersize=2)
    plt.title("Температура во времени")
    plt.xlabel("Время")
    plt.ylabel("°C")
    plt.xticks(rotation=45)
    plt.grid(True)

    # === 2. Гистограмма — напряжение ===
    plt.subplot(1, 3, 2)
    plt.hist(data['voltage'], bins=10, color='steelblue', edgecolor='black')
    plt.title("Распределение напряжения")
    plt.xlabel("Вольты")
    plt.ylabel("Частота")
    plt.grid(axis='y')

    # === 3. Круговая диаграмма — движение ===
    motion_counts = {0: data['motion'].count(0), 1: data['motion'].count(1)}
    plt.subplot(1, 3, 3)
    plt.pie(
        [motion_counts[0], motion_counts[1]],
        labels=["Нет движения", "Движение"],
        autopct='%1.1f%%',
        colors=['lightgreen', 'tomato'],
        shadow=True,
        startangle=90
    )
    plt.title("Доля времени с движением")

    plt.tight_layout()
    plt.savefig("pr8_visualization.png")
    plt.show()

if __name__ == "__main__":
    main()