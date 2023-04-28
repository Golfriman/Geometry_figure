# Geometry_Figure
## Описание
 Тестовое задание для Топ Систем
Стек технологий:
 - C++17
 - WinAPI
## Функции, которые были реализованы:
 1. Возможность создания фигур: 
    - Линяя
    - Прямоугольник
    - Окружность, при компиляции можно менять детализацию окружности (по умолчанию 30)
    - Полигон
 2. Возможность менять цвет фигур (пока, что при компиляции проекта)
 3. Возможность создавать элементы на форме при помощи кнопок:
     </br>○ - Рисовать окружность из центра
     </br>\ - Рисовать линию по двум точкам
     </br>□ - Рисовать прямоугольник по двум точкам, начиная слевого верхнего угла
     </br>⎔ - Рисовать полигон (погрешность между пиксилями 20)
     </br>◧ - Очистить текущее полотно

# Структура проекта
```mermaid
classDiagram
    class InputHandler
        InputHandler: +Command* handleInput(idCommand)

    class Command
    <<Abstract>> Command
        Command: +Factory* execute()*

    InputHandler --> Command

    class LineCommand
        LineCommand: +Factory* execute()*

    class CircleCommand
        CircleCommand: +Factory* execute()*

    class ClearCommand
        ClearCommand: +Factory* execute()*

    class PolygonCommand
        PolygonCommand: +Factory* execute()*

    class BoxCommand
        BoxCommand: +Factory* execute()*

    Command <|-- LineCommand
    Command <|-- CircleCommand
    Command <|-- BoxCommand
    Command <|-- ClearCommand
    Command <|-- PolygonCommand

    class Factory
    <<Abstarct>> Factory
        Factory: +bool buildShape(x, y)*
        Factory: +Shape* endBuild()*
        Factory: +Shape* tempBuild()*

    Command --> Factory


    class BoxFactory
        BoxFactory: +bool buildShape(x, y)*
        BoxFactory: +Shape endBuild()*
        BoxFactory: +Shape tempBuild(x, y)*
    class LineFactory
        LineFactory: +bool buildShape(x, y)*
        LineFactory: +Shape endBuild()*
        LineFactory: +Shape tempBuild(x, y)*
    class CircleFactory
        CircleFactory: +bool buildShape(x, y)*
        CircleFactory: +Shape endBuild()*
        CircleFactory: +Shape tempBuild(x, y)*
    class ClearFactory
        ClearFactory: +bool buildShape(x, y)*
        ClearFactory: +Shape endBuild()*
        ClearFactory: +Shape tempBuild(x, y)*
    class PolygonFactory 
        PolygonFactory: +bool buildShape(x, y)*
        PolygonFactory: +Shape endBuild()*
        PolygonFactory: +Shape tempBuild(x, y)*

    Factory <|-- BoxFactory
    Factory <|-- LineFactory
    Factory <|-- CircleFactory
    Factory <|-- ClearFactory   
    Factory <|-- PolygonFactory

    class Shape
    <<Abstarct>> Shape
        Shape: +void changeColorPen(Color)
        Shape: +void changeStylePen(iStyle)
        Shape: +changeWidthPen(cWidth)
        Shape: +void setHPEN(pen)
        Shape: +void draw(hdc)*

    Factory --> Shape

    class Box
        Box: +void draw(hdc)*
        Box: +void setLeftUpPoint(x, y)
        Box: +void setWidth(width)
        Box: +void setHeight(h)
    
    class Circle
        Circle: +void draw(hdc)*
        Circle: +void setDetalization(d)
    
    class Line
        Line: +void draw(hdc)*

    class Polygon
        Polygon: -list< Point > points
        Polygon: +void draw(hdc)*
        Polygon: +Polygon* clone()
        Polygon: +void addPoint(p)

    class Point
        Point: +x
        Point: +y
    Polygon *-- Point

    Shape <|-- Box
    Shape <|-- Circle
    Shape <|-- Line
    Shape <|-- Polygon

    class Scene
        Scene: +void draw(hdc)
        Scene: +void drawTempShape(hdc)
        Scene: +void addShape(*shape)
        Scene: -list < Shape* > shapes

    Scene *-- Shape
```

 ## Экранные формы:
 - Форма при запуске приложения </br>
 ![Форма при запуске приложения](./img/0.png) 
 - Форма после того как нарисовали круг </br>
 ![Форма после того как нарисовали круг](./img/1.png)
 - Форма после того как нарисовали линию </br>
 ![Форма после того как нарисовали линию](./img/2.png)
 - Форма после того как нарисовали прямоугольник </br>
 ![Форма после того как нарисовали прямоугольник](./img/3.png)
 - Форма после того как нарисовали полигон </br>
 ![Форма после того как нарисовали полигон](./img/4.png)
 - Форма после нажатия "Очистка" </br>
 ![Форма после нажатия "Очистка"](./img/5.png)
 
