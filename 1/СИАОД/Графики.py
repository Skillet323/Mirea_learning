# import matplotlib.pyplot as plt
# import numpy as np

# groups = ["Husquarna", "H max", "Bosch", "B max", "Gardena", "G max", "Robomow", "R max"]
# counts = [70000, 350000, 80000, 130000, 70000, 175000, 55000, 300000]
# colors = ['tab:green', 'tab:green', 'tab:blue', 'tab:blue', 'tab:orange', 'tab:orange', 'tab:pink', 'tab:pink']

# fig, ax = plt.subplots(figsize=(10, 6))

# def update(frame):
#     ax.clear()
#     for i, (group, count, color) in enumerate(zip(groups, counts, colors)):
#         if frame / 100 > count / max(counts):
#             ax.bar(group, count, color=color, edgecolor="k", linewidth=2)
#         else:
#             ax.bar(group, frame / 100 * count, color=color, edgecolor="k", linewidth=2)
#     ax.set_ylabel('Цена в рублях')
#     ax.set_xlabel('Фирмы')
#     ax.set_ylim(0, max(counts))

# # Создаем анимацию
# frames = np.arange(0, 101, 5)  # 0% до 100% с шагом 5%
# for i, frame in enumerate(frames):
#     update(frame)
#     plt.savefig(f'frame_{i:03d}.png')

# # Конвертируем изображения в анимацию
# import glob
# import imageio

# images = []
# for filename in sorted(glob.glob('frame_*.png')):
#     images.append(imageio.imread(filename))
# imageio.mimsave('animated_noise.gif', images, fps=10)

# plt.show()


# n=np.array([10000,100000,1000000])
# y=np.array([783542,9641569,112967595])
# y1=np.array([49605128,648864620,1228144492])
# y2=np.array([252166,3104824,38635862])
# plt.xlabel('Значения n')
# plt.ylabel('Количество операций сравнения и перемещения')
# plt.plot(n,y,'g',label='Сортировка слияния')
# plt.plot(n,y1,'r',label='Сортировка вставками')
# plt.plot(n,y2,'b',label='Сортировка Шелла')
# plt.legend()
# plt.show()



import pandas as pd
from prettytable import PrettyTable
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Создаем DataFrame с моделями и их ценами
# data = {
#     "Фирма": ["Husqvarna", "Husqvarna", "Husqvarna",
#               "Bosch", "Bosch", "Bosch",
#               "Gardena", "Gardena", "Gardena",
#               "Robomow", "Robomow", "Robomow"],
#     "Модель": ["Automower 105", "Automower 310", "Automower 430X",
#                "Indego S+ 350", "Indego M 700", "Indego M+ 800",
#                "Sileno city 500", "Sileno life 1000", "Sileno city 2500",
#                "RX12u", "RC308", "RC312"],
#     "Цена (руб.)": [50000, 90000, 150000,
#                     60000, 100000, 130000,
#                     55000, 80000, 110000,
#                     40000, 70000, 100000]
# }
# df = pd.DataFrame(data)

# Создаем DataFrame с моделями и их характеристиками
import pandas as pd
from prettytable import PrettyTable
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Создаем DataFrame с моделями и их характеристиками
data = {
    "Фирма": ["Husqvarna", "Husqvarna", "Husqvarna",
              "Bosch", "Bosch", "Bosch",
              "Gardena", "Gardena", "Gardena",
              "Robomow", "Robomow", "Robomow"],
    "Модель": ["Automower 105", "Automower 310", "Automower 430X",
               "Indego S+ 350", "Indego M 700", "Indego M+ 800",
               "Sileno city 500", "Sileno life 1000", "Sileno city 2500",
               "RX12u", "RC308", "RC312"],
    "Электрическая мощность (Вт)": [100, 150, 200,
                                    120, 180, 220,
                                    110, 160, 210,
                                    90, 140, 170],
    "Энергопотребление (кВт·ч/сезон)": [50, 75, 100,
                                         60, 90, 110,
                                         55, 80, 105,
                                         45, 70, 85]
}
df = pd.DataFrame(data)

print("Таблица Электрической мощности и Энергопотребления различных моделей роботов:")
print(df)

# Создаем PrettyTable с настройками оформления
table = PrettyTable()
table.field_names = ["Фирма", "Модель", "Электрическая мощность (Вт)", "Энергопотребление (кВт·ч/сезон)"]
table.align["Фирма"] = "l"  # Выравнивание текста по левому краю для колонки "Фирма"
table.align["Модель"] = "l"  # Выравнивание текста по левому краю для колонки "Модель"
table.align["Электрическая мощность (Вт)"] = "r"  # Выравнивание текста по правому краю для колонки "Электрическая мощность (Вт)"
table.align["Энергопотребление (кВт·ч/сезон)"] = "r"  # Выравнивание текста по правому краю для колонки "Энергопотребление (кВт·ч/сезон)"
table.header = True  # Отображение заголовка таблицы
table.horizontal_char = '-'  # Горизонтальная черта
table.vertical_char = '|'  # Вертикальная черта
table.junction_char = '+'  # Знак соединения

# Добавляем данные в таблицу PrettyTable
for i in range(12):
    row = [df.iloc[i, 0], df.iloc[i, 1], df.iloc[i, 2], df.iloc[i, 3]]
    table.add_row(row)

# Отображаем PrettyTable
print("Красиво оформленная таблица с использованием PrettyTable:")
print(table)

# Создаем функцию для анимации появления строк в таблице
def update_table(frame):
    ax.clear()  # Очищаем предыдущий график
    # Печатаем таблицу со строками до номера frame
    ax.text(0, 0.8, str(table[:frame]), va='center', ha='left', fontsize=12, family='monospace', color='black')
    ax.axis('off')  # Убираем оси координат
    ax.set_xticks([])  # Убираем деления на оси X
    ax.set_yticks([])  # Убираем деления на оси Y
    return ax,

# Создаем анимацию появления строк в таблице
fig, ax = plt.subplots(figsize=(12, 6))
ani = animation.FuncAnimation(fig, update_table, frames=len(table._rows)+1, repeat=False)

# Сохраняем анимацию в виде gif
ani.save('Power.gif', writer='imagemagick', fps=1)

plt.show()


# print("Таблица Электрической мощности и Энергопотребления различных моделей роботов:")
# print(df)

# # Создаем PrettyTable с настройками оформления
# table = PrettyTable()
# table.field_names = ["Фирма", "Модель", "Цена (руб.)"]
# table.align["Фирма"] = "l"  # Выравнивание текста по левому краю для колонки "Фирма"
# table.align["Модель"] = "l"  # Выравнивание текста по левому краю для колонки "Модель"
# table.align["Цена (руб.)"] = "r"  # Выравнивание текста по правому краю для колонки "Цена (руб.)"
# table.header = True  # Отображение заголовка таблицы
# table.horizontal_char = '-'  # Горизонтальная черта
# table.vertical_char = '|'  # Вертикальная черта
# table.junction_char = '+'  # Знак соединения

# # Добавляем данные в таблицу PrettyTable
# for i in range(12):
#     row = [df.iloc[i, 0], df.iloc[i, 1], df.iloc[i, 2]]
#     table.add_row(row)

# # Устанавливаем стилизацию таблицы
# table.header = True  # Отображение заголовка таблицы
# table.horizontal_char = '-'  # Горизонтальная черта
# table.vertical_char = '|'  # Вертикальная черта
# table.junction_char = '+'  # Знак соединения

# # Отображаем PrettyTable
# print("Красиво оформленная таблица с использованием PrettyTable:")
# print(table)

# # Создаем функцию для анимации появления строк в таблице
# def update_table(frame):
#     ax.clear()  # Очищаем предыдущий график
#     # Печатаем таблицу со строками до номера frame
#     ax.text(0, 0.8, str(table[:frame]), va='center', ha='left', fontsize=12, family='monospace', color='black')
#     ax.axis('off')  # Убираем оси координат
#     ax.set_xticks([])  # Убираем деления на оси X
#     ax.set_yticks([])  # Убираем деления на оси Y
#     return ax,
# # Создаем анимацию появления строк в таблице
# fig, ax = plt.subplots(figsize=(6, 6))
# ani = animation.FuncAnimation(fig, update_table, frames=len(table._rows)+1, repeat=False)

# # Сохраняем анимацию в виде gif
# ani.save('Power.gif', writer='imagemagick', fps=1)

# plt.show()




# import matplotlib.pyplot as plt
# import numpy as np

# models = ["Husqvarna Automower 315X", "Honda Miimo HRM 310", "Bosch Indego S+ 400", "Worx Landroid WR140", "Gardena Sileno City", "Robomow RS630", "Flymo 1200R", "Ambrogio L30 Elite"]
# noises_dB = [58, 62, 55, 60, 60, 64, 57, 63]  # Уровень шума в дБ
# colors = ['tab:green', 'tab:purple', 'tab:blue', 'tab:red', 'tab:orange', 'tab:brown', 'tab:pink', 'tab:cyan']

# fig, ax = plt.subplots(figsize=(10, 6))

# def update(frame):
#     ax.clear()
#     for model, noise, color in zip(models, noises_dB, colors):
#         if frame / 100 > noise / max(noises_dB):
#             ax.bar(model, noise, color=color, edgecolor="k", linewidth=2, label=model)
#         else:
#             ax.bar(model, frame / 100 * noise, color=color, edgecolor="k", linewidth=2, label=model)
#     ax.set_ylabel('Уровень шума, дБ')
#     ax.set_xlabel('Модели')
#     ax.set_ylim(0, max(noises_dB) * 1.1)
#     ax.legend(loc='upper right')

#     # Пустые значения в нижней части
#     ax.set_xticks([])
#     ax.set_xticklabels([])

# # Создаем анимацию
# frames = np.arange(0, 101, 5)  # 0% до 100% с шагом 5%
# for i, frame in enumerate(frames):
#     update(frame)
#     plt.savefig(f'frame_{i:03d}.png')

# # Конвертируем изображения в анимацию
# import glob
# import imageio

# images = []
# for filename in sorted(glob.glob('frame_*.png')):
#     images.append(imageio.imread(filename))
# imageio.mimsave('animated_noise.gif', images, fps=10)
