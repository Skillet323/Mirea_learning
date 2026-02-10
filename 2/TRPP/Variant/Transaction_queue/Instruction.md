# INSTRUCTION FOR LAUNCH
## Измененение файлов
В zip - добавить нужные payments и transactions, а также features и labels (если имеются)

В main.ipynb прописать пути/названия новых файлов

## Создание образа в Docker

docker build -t hackk-container .

## Создание контейнера

docker run -d --name hackk-runner -p 8888:8888 hackk-container

