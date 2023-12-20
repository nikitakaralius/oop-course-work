# Курсовая работа по ТООП
## Разработка приложения для анализа файловой системы

### Сборка LaTeX

```shell
cd docs/latex
pdflatex My_thesis.pdf
```

### Сборка Docker контейнера
```shell
docker build . -t oop-course-work:latest
```

### Запуск Docker контейнера
В приложении используется взаимодействие с пользователем через cin/cout.
Необходимо запускать контейнер в интерактивном режиме:
```shell
docker run -it oop-course-work:latest /bin/bash
```