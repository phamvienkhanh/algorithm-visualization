#include <SFML/Graphics.hpp>

static const int recWidth     = 20;
static const int recMaxHeight = 350;
static const int winWidth     = 800;
static const int winHeight    = 500;

typedef struct RecData
{
    sf::IntRect rec;
    sf::Color   colorRec;
};

void RenderListRectangle(sf::RenderTexture& renderTexture)
{
    std::vector<RecData> listItem;
    for (int i = 0; i < 40; ++i)
    {
        RecData recData;

        int randHeight = std::rand() % recMaxHeight;
        sf::IntRect  rec(i * recWidth, winHeight - randHeight, recWidth, randHeight);
        recData.rec = rec;
        recData.colorRec = sf::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256);
        listItem.push_back(recData);
    }

    renderTexture.clear();

    for (auto rec = listItem.begin(); rec != listItem.end(); ++rec)
    {
        sf::RectangleShape rectangle(sf::Vector2f(rec->rec.width, rec->rec.height));
        rectangle.setPosition(sf::Vector2f(rec->rec.left, rec->rec.top));
        rectangle.setFillColor(rec->colorRec);
        renderTexture.draw(rectangle); // or any other drawable
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "SFML works!");

    sf::RenderTexture renderTexture;
    renderTexture.create(winWidth, winHeight);
    renderTexture.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        RenderListRectangle(renderTexture);
        
        sf::Sprite sptite(renderTexture.getTexture());

        window.clear();
        window.draw(sptite);
        window.display();
    }

    return 0;
}