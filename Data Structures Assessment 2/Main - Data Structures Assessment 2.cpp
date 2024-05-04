#pragma warning(disable : 4996)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <map>
#include <vector>
#include <string>

enum class StoreSize { Small = 1, Medium = 2, Large = 3 }; // Defines an enum to store the size of store to be created

class FileManipulation // Class for handling all file manipulation tasks
{
protected:
    std::string filename; // String to store filename in
public:
    std::string setFilename(std::string storeName) // Function to set the filename depending on the currently selected store
    {
        if (storeName == "Treforest")
        {
            return "smallProducts.txt";
        }
        else if (storeName == "Pontypridd")
        {
            return "mediumProducts.txt";
        }
        else if (storeName == "Cardiff")
        {
            return "largeProducts.txt";
        }
        else
        {
            return "defaultProducts.txt";
        }
    }
    void writeProductsToFile() // Function to initialise item files on programs first run
    {
        uint16_t uint16_productSku = 1000;
        std::map<uint16_t, std::pair<std::string, double>> defaultProducts;
        std::map<uint16_t, std::pair<std::string, double>> smallProducts;
        std::map<uint16_t, std::pair<std::string, double>> mediumProducts;
        std::map<uint16_t, std::pair<std::string, double>> largeProducts;

        std::ofstream defaultProductExport("defaultProducts.txt", std::ios::out);
        std::ofstream smallProductExport("smallProducts.txt", std::ios::out);
        std::ofstream mediumProductExport("mediumProducts.txt", std::ios::out);
        std::ofstream largeProductExport("largeProducts.txt", std::ios::out);

        defaultProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Safety Boots", 32.99)));
        uint16_productSku++;
        defaultProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Safety Helmet", 10.99)));
        uint16_productSku++;
        defaultProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Safety Gloves", 4.99)));
        uint16_productSku++;
        defaultProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Safety Glasses", 2.99)));
        uint16_productSku++;

        smallProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Paint Brush", 2.99)));
        uint16_productSku++;
        smallProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Paint Roller", 3.99)));
        uint16_productSku++;
        smallProducts.insert(std::make_pair(uint16_productSku, std::make_pair("10l White Paint", 12.99)));
        uint16_productSku++;
        smallProducts.insert(std::make_pair(uint16_productSku, std::make_pair("10l Magnolia Paint", 12.99)));
        uint16_productSku++;

        mediumProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Cordless Combi Drill", 122.99)));
        uint16_productSku++;
        mediumProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Cordless Impact Driver", 145.99)));
        uint16_productSku++;
        mediumProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Cordless Twin Pack (Combi & Impact)", 175.99)));
        uint16_productSku++;
        mediumProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Cordless 4inch Angle Grinder", 125.99)));
        uint16_productSku++;

        largeProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Wheelbarrow", 32.99)));
        uint16_productSku++;
        largeProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Sink", 44.99)));
        uint16_productSku++;
        largeProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Toilet System", 55.99)));
        uint16_productSku++;
        largeProducts.insert(std::make_pair(uint16_productSku, std::make_pair("Fence Panels", 25.99)));
        uint16_productSku++;

        // TODO Add accessory items for each store after checkout created

        if (defaultProductExport.is_open())
        {
            for (const auto& product : defaultProducts)
            {
                defaultProductExport << product.first << "," << product.second.first << "," << product.second.second << std::endl;
                std::cout << "Writing product " << product.first << " to file." << std::endl;
            }
            std::cout << "Closing file" << std::endl;
            defaultProductExport.close();
        }
        if (smallProductExport.is_open())
        {
            for (const auto& product : defaultProducts)
            {
                smallProductExport << product.first << "," << product.second.first << "," << product.second.second << std::endl;
                std::cout << "Writing product " << product.first << " to file." << std::endl;
            }

            for (const auto& product : smallProducts)
            {
                smallProductExport << product.first << "," << product.second.first << "," << product.second.second << std::endl;
                std::cout << "Writing product " << product.first << " to file." << std::endl;
            }
            std::cout << "Closing file" << std::endl;
            smallProductExport.close();
        }
        if (mediumProductExport.is_open())
        {
            for (const auto& product : defaultProducts)
            {
                mediumProductExport << product.first << "," << product.second.first << "," << product.second.second << std::endl;
                std::cout << "Writing product " << product.first << " to file." << std::endl;
            }

            for (const auto& product : mediumProducts)
            {
                mediumProductExport << product.first << "," << product.second.first << "," << product.second.second << std::endl;
                std::cout << "Writing product " << product.first << " to file." << std::endl;
            }
            std::cout << "Closing file" << std::endl;
            mediumProductExport.close();
        }
        if (largeProductExport.is_open())
        {
            for (const auto& product : defaultProducts)
            {
                largeProductExport << product.first << "," << product.second.first << "," << product.second.second << std::endl;
                std::cout << "Writing product " << product.first << " to file." << std::endl;
            }

            for (const auto& product : largeProducts)
            {
                largeProductExport << product.first << "," << product.second.first << "," << product.second.second << std::endl;
                std::cout << "Writing product " << product.first << " to file." << std::endl;
            }
            std::cout << "Closing file" << std::endl;
            largeProductExport.close();
        }
    }

    std::map<uint16_t, std::pair<std::string, double>> readProductsFromFile(std::string filename) // Function to read all the items from the relevant products file based on the selected store
    {
        std::map<uint16_t, std::pair<std::string, double>> products; // Creates a map to store all products in taking an item number, then name and price as a pair using string and double respectively
        //std::map<uint16_t, std::pair<std::string, double>> accessories; // This would have stored the available accessories for the store if I had time to implement this
        std::ifstream productImport(filename); // Creates an ifstream stream to get the product details from the products file

        if (productImport.is_open()) // If statement checks if the stream is open
        {
            std::string product; // Creates a string to store each product in before separating into the map
            while (std::getline(productImport, product)) // While loop uses getline to pull each line from the file and stores it in product string
            {
                std::stringstream ss(product); // Stringstream to separate the product number, product name and price from the product string
                std::string field; // Temporary string to store the separated details
                std::vector<std::string> fields; // Creates a vector to store each part of the product details
                while (std::getline(ss, field, ',')) // While loop to extract all the details from the stringstream, separating on the comma and storing in field string
                {
                    fields.push_back(field); // Sends all the separated values into the vector
                }
                uint16_t sku = std::stoi(fields[0]); // Converts and stores the value held in the first position of the vector from string to int in sku
                std::string name = fields[1]; // Stores the value held in the second position of the vector in name
                double price = std::stod(fields[2]); // // Converts and stores the value held in the third position of the vector from string to double in price
                products.insert(std::make_pair(sku, std::make_pair(name, price))); // Inserts all the product details into the products map
            }
            productImport.close(); // Closes the products ifstream filestream
        }
        return products; // Returns the products map to Store constructor
    }

    void writeOrdersToFile(std::string order, std::string filename) // Function responsible for sending order details to the orders file based on currently selected store
    {
        std::ofstream orderOutputToFile(filename, std::ios::app); // Creates an ofstream stream to send the order details to the orders file in append mode
        if (orderOutputToFile.is_open()) // If statement checks if the stream is open
        {
            orderOutputToFile << order; // Sends the passed order parameter to the filestream ofstream
            orderOutputToFile.close(); // Closes the orders ofstream filestream
        }
        else
        {
            std::cout << "Couldn't write order to file..." << std::endl; // Error handling for if the file couldn't be opened
        }
    }
    void readOrdersFromFile(std::string filename) // Function if implemented would have been responsible for listing all orders for the store along with seeding the order number with incremented previous order number value
    {
        // TODO read orders from file
        std::ifstream orderInputFromFile(filename); // Creates an ifstream stream to read the order details from the orders file
        if (orderInputFromFile.is_open()) // If statement checks if the stream is open
        {
            // TODO store orders in new orders map then take the value for order number from that
            orderInputFromFile.close(); // Closes the orders ifstream filestream
        }
        else
        {
            std::cout << "Couldn't read order from file..." << std::endl; // Error handling for if the file couldn't be opened
        }
    }
};

class Listener // Class responsible for product tracking - Implemented partially working
{
public:
    virtual void onEvent(uint16_t uint16_orderNumber, const std::vector<uint16_t>& productNumbers, std::string storeName) = 0; // Function to call when orders are placed to add them to the tracking
    virtual void displayOrders() = 0; // Function to display all orders currently being tracked
};

class Publisher // Class responsible for updating listeners
{
protected:
    std::vector<Listener*> listeners; // Vector to store listeners
public:
    void addListener(Listener* listener) // Function to create listeners
    {
        listeners.push_back(listener); // Pushes back created listener object to the vector
    }
    void removeListener(Listener* listener) // Function to delete all listeners
    {
        listeners.clear(); // Clears the listeners vector
    }
    void notify(uint16_t uint16_orderNumber, const std::vector<uint16_t>& productNumbers, std::string storeName) // Function to notify the listeners of changes
    {
        for (auto listener : listeners) // For loop to loop through all listeners
        {
            listener->onEvent(uint16_orderNumber, productNumbers, storeName); // Update the current listener with the details by calling onEvent
        }
    }
    void update(uint16_t uint16_orderNumber, const std::vector<uint16_t>& productNumbers, std::string storeName) // Functin to update the listeners
    {
        notify(uint16_orderNumber, productNumbers, storeName); // Calls notify function to update the listeners with new details
    }
};

class orderListener : public Listener // Class for creating orderListener inheriting Listener
{
protected:
    std::vector<uint16_t> products; // Creates a vector to store products in
public:
    orderListener(Publisher& p) // orderListener constructor creates a new pointer reference to Publisher class
    {
        p.addListener(this); // Creates a new listener passing this pointer to it
    }
    void onEvent(uint16_t uint16_orderNumber, const std::vector<uint16_t>& productNumbers, std::string storeName) override // Function responsible for updating files for deliveryTracking
    {
        std::cout << "Delivery Tracking Update: Order Number - " << uint16_orderNumber << " is now being tracked." << std::endl;
        std::ofstream deliveryFile("deliveriesTracking.txt", std::ios::app);
        if (deliveryFile.is_open())
        {
            auto current = std::chrono::system_clock::now();
            auto currentTime = std::chrono::system_clock::to_time_t(current);
            localtime(&currentTime);
            std::chrono::hours delivery_period(24);
            auto deliveryTime = current + delivery_period;
            auto t_deliveryTime = std::chrono::system_clock::to_time_t(deliveryTime);
            std::stringstream ss;
            ss << std::put_time(std::localtime(&t_deliveryTime), "%Y-%m-%d %H:%M:%S");
            std::string str_deliveryTime = ss.str();

            std::string output = "";
            output += "Order number: " + std::to_string(uint16_orderNumber) + "\n";
            output += "Store: " + storeName + "\n";
            output += "Delivery time: " + str_deliveryTime + "\n";
            output += "Item Numbers: ";
            for (auto productNumber : productNumbers)
            {
                output += std::to_string(productNumber) + ", ";
            }
            output += "\n";
            deliveryFile << output;
            deliveryFile.close();
        }
        else
        {
            std::cout << "Failed to open file..." << std::endl;
            return;
        }
    }
    void displayOrders() override // Function responsible for displaying orders currently being tracked
    {
        std::ifstream deliveryFile("deliveriesTracking.txt");
        if (deliveryFile.is_open())
        {
            std::cout << "Deliveries: " << std::endl;
            std::string order;
            while (std::getline(deliveryFile, order))
            {
                std::istringstream iss(order); // Pull order number
                std::string token;
                std::getline(iss, token, ':');
                std::getline(iss >> std::ws, token, ',');
                std::string orderNumber = token.substr(1);
                
                std::getline(iss, token, ':'); // Pull storename
                std::getline(iss >> std::ws, token, ',');
                std::string storeName = token;
                
                std::getline(iss, token, ':'); // Pull delivery time
                std::getline(iss >> std::ws, token, ',');
                std::istringstream StringStream(token);
                std::tm deliveryTime = {};
                StringStream >> std::get_time(&deliveryTime, "%Y-%m-%d %H:%M:%S");
                std::time_t t_deliveryTime = std::mktime(&deliveryTime);

                auto current = std::chrono::system_clock::now(); // Get the current time
                auto deliveryTimePoint = std::chrono::system_clock::from_time_t(t_deliveryTime); // Convert delivery time to a time_point
                auto timeDifference = std::chrono::duration_cast<std::chrono::minutes>(deliveryTimePoint - current); // Calculate time difference between current and delivery time
                
                int hours = std::chrono::duration_cast<std::chrono::hours>(timeDifference).count() % 24; // Extract hours, and minutes from time difference
                int minutes = timeDifference.count() % 60;

                std::getline(iss, token, ':'); // pull products numbers
                std::getline(iss >> std::ws, token);
                std::string productNumbers = token;

                productNumbers.erase(std::remove(productNumbers.begin(), productNumbers.end(), ','), productNumbers.end()); // remove commas from product numbers

                std::cout << "Order number: " << orderNumber << std::endl;
                std::cout << "Branch: " << storeName << std::endl;
                std::cout << "Item numbers: " << productNumbers << std::endl;
                std::cout << "Expected delivery date/time: " << std::put_time(&deliveryTime, "%Y-%m-%d %H:%M:%S") << std::endl;
                std::cout << "Time remaining: " << hours << " hours, " << minutes << " minutes" << std::endl;
            }
        }
        else
        {
            std::cout << "Failed to open file..." << std::endl;
            return;
        }
    }
};

class Store // Base Store class, all stores inherit this one upon creation
{
protected:
    FileManipulation fileManipulation; // Filemanipulation object
    std::map<uint16_t, std::pair<std::string, double>> Products; // Stores products for the store
    std::map<uint16_t, std::pair<std::string, double>> Basket; // Basket to add items to when ordering
    //std::map<uint16_t, uint16_t, std::pair<std::string, double>, double> Orders; // Would have stored orders for the store in a map to display in the list all orders
    bool paymentCompleted = false; // Boolean to check when payment is processed
    double orderTotal = 0; // double for order total variable
    uint16_t uint16_orderNumber = 1000; // TODO change this to initialise from the file
public:
    std::string storeName = ""; // String to store store name
    std::string filename = fileManipulation.setFilename(storeName); // Sets the filename based off the currently selected store

    Store() // Constructor for the store this handles creating files if they don't currently exist on the system
    {
        std::ifstream defaultExist("defaultProducts.txt");
        std::ifstream smallExist("smallProducts.txt");
        std::ifstream mediumExist("mediumProducts.txt");
        std::ifstream largeExist("largeProducts.txt");
        if (defaultExist.is_open() && smallExist.is_open() && mediumExist.is_open() && largeExist.is_open())
        {
            std::cout << "Product Files Found." << std::endl;
        }
        else
        {
            fileManipulation.writeProductsToFile();
            std::cout << "Writing products to file." << std::endl;
        }
        defaultExist.close();
        smallExist.close();
        mediumExist.close();
        largeExist.close();
    }
    virtual ~Store() {};
    virtual std::string setStoreName() = 0;
    virtual void resetStoreName() { storeName = ""; } // This would have been used for the change store functionality allowing the user to change store without having to quit

    virtual void storeMainMenu() // Function for the stores main menu this handles user input and sends the user on their journey through the program
    {
        Publisher publisher;
        orderListener* orderTracker = new orderListener(publisher);
        bool storeMenuLoop = true;
        uint16_t uint16_menuSelection = 0;
        while (storeMenuLoop)
        {
            std::cout << "------------" << std::endl;
            std::cout << "Hello and welcome to " << storeName << "'s Mend-It Store" << std::endl;
            std::cout << "How can we help you today?" << std::endl;
            std::cout << "1 - View Orders" << std::endl;
            std::cout << "2 - Place Order" << std::endl;
            std::cout << "3 - Track Orders" << std::endl;
            std::cout << "4 - Change Store" << std::endl;
            std::cout << "0 - Quit" << std::endl;
            std::cout << "Selection: ";
            std::cin >> uint16_menuSelection;
            if (std::cin.fail())
            {
                std::cout << "Invalid input, please enter a valid integer value..." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                if (uint16_menuSelection == 1 || uint16_menuSelection == 2 || uint16_menuSelection == 3 || uint16_menuSelection == 4)
                {
                    if (uint16_menuSelection == 1)
                    {
                        std::cout << "List of orders" << std::endl;
                    }
                    else if (uint16_menuSelection == 2)
                    {
                        std::cout << "Place order online or instore?" << std::endl;
                        displayProducts(filename);
                    }
                    else if (uint16_menuSelection == 3)
                    {
                        std::cout << "Tracking for active orders" << std::endl;
                        orderTracker->displayOrders();
                        std::cout << std::endl;
                    }
                    else if (uint16_menuSelection == 4)
                    {
                        std::cout << "Change store" << std::endl;
                        return;
                    }
                }
                else if (uint16_menuSelection < 0 || uint16_menuSelection > 4)
                {
                    std::cout << "Invalid choice, please enter number between 0 and 3..." << std::endl;
                }
                else if (uint16_menuSelection == 0)
                {
                    std::cout << "Exiting program..." << std::endl;
                    storeMenuLoop = false;
                }
            }
        }
    }

    virtual void displayProducts(std::string filename) // Function to display all products to the user then sends them to the order products function
    {
        Products = fileManipulation.readProductsFromFile(filename);
        std::cout << "Product List" << std::endl;
        std::cout << "------------" << std::endl;
        for (const auto& product : Products)
        {
            std::cout << std::fixed << std::setprecision(2) << "SKU: " << product.first << ", Product: " << product.second.first << ", Price: £" << product.second.second << std::endl;
        }
        std::cout << "------------" << std::endl;
        orderProducts();
    }
    virtual void orderProducts() // Function to order products and add them to the basket then send them to the checkout section when user has added everything they wish to add
    {
        bool orderingLoop = true;
        bool itemExists = false;
        bool anotherItemLoop = true;
        uint16_t uint16_itemSelected = 0;
        while (orderingLoop)
        {
            std::cout << "Please enter item number you wish to add to your basket: ";
            std::cin >> uint16_itemSelected;
            if (std::cin.fail())
            {
                std::cout << "Invalid input, please enter a valid integer value..." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                for (auto& product : Products)
                {
                    if (product.first == uint16_itemSelected)
                    {
                        Basket[uint16_itemSelected] = std::make_pair(product.second.first, product.second.second);
                        orderTotal += product.second.second;
                        std::cout << "Added SKU " << product.first << ", " << product.second.first << " to basket" << std::endl;
                        itemExists = true;
                    }
                    else if (uint16_itemSelected == 0)
                    {
                        orderingLoop = false;
                    }
                }
                if (!itemExists)
                {
                    std::cout << "Item not found..." << std::endl;
                }
                while (anotherItemLoop)
                {
                    std::cout << "Would you like to add another item to your basket? (y/n): ";
                    char response;
                    std::cin >> response;
                    if (response == 'y' || response == 'Y')
                    {
                        orderingLoop = true;
                        break;
                    }
                    else if (response == 'n' || response == 'N')
                    {
                        orderingLoop = false;
                        anotherItemLoop = false;
                    }
                    else
                    {
                        std::cout << "Please enter a valid response..." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            }
        }
        if (Basket.size() > 0)
        {
            checkout();
        }
    }
    virtual void checkout() // Function to display all the items in the basket to the user and send them to the payment section
    {
        std::cout << std::endl;
        std::cout << "----- Check out -----" << std::endl;
        std::cout << std::endl;
        for (const auto& product : Basket)
        {
            std::cout << std::fixed << std::setprecision(2) << "SKU: " << product.first << ", Product: " << product.second.first << ", Price: £" << product.second.second << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::fixed << std::setprecision(2) << "Order total: £" << orderTotal << std::endl;
        payment();
    }
    void payment() // Function to confirm or cancel the order and accept payment from the user then send them to the print receipt function
    {
        double amountPaid = 0;
        double changeDue = 0;
        double amountDue = orderTotal - amountPaid;
        double tempInput = 0;
        bool confirmPaymentLoop = true;
        bool paymentConfirmedLoop = false;

        while (confirmPaymentLoop)
        {
            std::cout << "Would you like to continue and pay? (y/n): ";
            char response;
            std::cin >> response;
            if (response == 'y' || response == 'Y')
            {
                confirmPaymentLoop = true;
                break;
            }
            else if (response == 'n' || response == 'N')
            {
                std::cout << "Cancelling order..." << std::endl;
                confirmPaymentLoop = false;
                paymentConfirmedLoop = true;
                Basket.clear();
                orderTotal = 0;
                break;
            }
            else
            {
                std::cout << "Please enter a valid response..." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        while (!paymentConfirmedLoop)
        {
            std::cout << std::endl;
            std::cout << "Payment started..." << std::endl;
            std::cout << "Initialising connection..." << std::endl;
            while (orderTotal > amountPaid)
            {
                std::cout << std::fixed << std::setprecision(2) << "Amount due: £" << amountDue << std::endl;

                std::cout << "Input amount to pay: £";
                std::cin >> tempInput;
                if (std::cin.fail())
                {
                    std::cout << "Invalid input, please enter amount to pay..." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else
                {
                    amountPaid += tempInput;
                    if (amountPaid >= orderTotal)
                    {
                        changeDue = amountPaid - orderTotal;
                        std::cout << std::fixed << std::setprecision(2) << "Amount paid: £" << amountPaid << std::endl;
                        std::cout << std::fixed << std::setprecision(2) << "Change due: £" << changeDue << std::endl;
                        std::cout << std::endl;
                        paymentConfirmedLoop = true;
                        printReciept(paymentCompleted = true);
                    }
                    else if (amountPaid < orderTotal)
                    {
                        amountDue = orderTotal - amountPaid;
                        std::cout << std::fixed << std::setprecision(2) << "Amount paid: £" << amountPaid << std::endl;
                    }
                }
            }
        }
    }
    void printReciept(bool& paymentCompleted) // Function to print the receipt for the user printing the order number, products ordered, and order total. Then adds the order details to tracking service and sending order to the file for the store
    {
        Publisher publisher;
        orderListener* listener = new orderListener(publisher);
        std::vector<uint16_t> productNumbers;
        if (paymentCompleted == true)
        {
            std::cout << "----- Receipt -----" << std::endl;
            std::cout << "Order number: " << uint16_orderNumber << std::endl;
            std::cout << "-------------------" << std::endl;
            for (const auto& product : Basket)
            {
                std::cout << std::fixed << std::setprecision(2) << "SKU: " << product.first << ", Product: " << product.second.first << ", Price: £" << product.second.second << std::endl;
                productNumbers.push_back(product.first);
            }
            std::cout << "-------------------" << std::endl;
            std::cout << std::fixed << std::setprecision(2) << "Order total: £" << orderTotal << std::endl;

            std::string receiptOutput = "";
            receiptOutput += "Order number: " + std::to_string(uint16_orderNumber) + "\n";
            for (const auto& product : Basket)
            {
                std::ostringstream formatPrice;
                formatPrice << std::fixed << std::setprecision(2) << product.second.second; // format price to 2 decimal places
                std::string priceStr = formatPrice.str();
                receiptOutput += "SKU: " + std::to_string(product.first) + ", Product: " + product.second.first + ", Price: £" + priceStr + "\n";
            }
            std::ostringstream formatTotal;
            formatTotal << std::fixed << std::setprecision(2) << orderTotal; // format order total to 2 decimal places
            std::string orderTotalStr = formatTotal.str();
            receiptOutput += "Order total: £" + orderTotalStr + "\n";
            fileManipulation.writeOrdersToFile(receiptOutput, storeName + "Orders.txt");
            publisher.notify(uint16_orderNumber, productNumbers, storeName);
            Basket.clear();
            orderTotal = 0;
            uint16_orderNumber++;
        }
        else
        {
            std::cout << "An error occured while processing payment, please try again..." << std::endl;
            Basket.clear();
            orderTotal = 0;
            return;
        }
    }
};

class TreforestStore : public Store // Class for the Treforest store this inherits store and is responsible for overriding display products function for the small store type
{
public:
    TreforestStore() { setStoreName(); };
    virtual ~TreforestStore() { resetStoreName(); };

    std::string setStoreName() override
    {
        storeName = "Treforest";
        return "Treforest";
    }
    void displayProducts(std::string filename) override
    {
        Products = fileManipulation.readProductsFromFile("smallProducts.txt");
        std::cout << "Product List" << std::endl;
        std::cout << "------------" << std::endl;
        for (const auto& product : Products)
        {
            std::cout << "SKU: " << product.first << ", Product: " << product.second.first << ", Price: " << product.second.second << std::endl;
        }
        std::cout << "------------" << std::endl;
        orderProducts();
    }
};

class PontypriddStore : public Store // Class for the Pontypridd store this inherits store and is responsible for overriding display products function for the medium store type
{
public:
    PontypriddStore() { setStoreName(); };
    virtual ~PontypriddStore() { resetStoreName(); };

    std::string setStoreName() override
    {
        storeName = "Pontypridd";
        return "Pontypridd";
    }
    void displayProducts(std::string filename) override
    {
        Products = fileManipulation.readProductsFromFile("mediumProducts.txt");
        std::cout << "Product List" << std::endl;
        std::cout << "------------" << std::endl;
        for (const auto& product : Products)
        {
            std::cout << "SKU: " << product.first << ", Product: " << product.second.first << ", Price: " << product.second.second << std::endl;
        }
        std::cout << "------------" << std::endl;
        orderProducts();
    }
};

class CardiffStore : public Store // Class for the Cardiff store this inherits store and is responsible for overriding display products function for the large store type
{
public:
    CardiffStore() { setStoreName(); };
    virtual ~CardiffStore() { resetStoreName(); };

    std::string setStoreName() override
    {
        storeName = "Cardiff";
        return "Cardiff";
    }
    void displayProducts(std::string filename) override
    {
        Products = fileManipulation.readProductsFromFile("largeProducts.txt");
        std::cout << "Product List" << std::endl;
        std::cout << "------------" << std::endl;
        for (const auto& product : Products)
        {
            std::cout << "SKU: " << product.first << ", Product: " << product.second.first << ", Price: " << product.second.second << std::endl;
        }
        std::cout << "------------" << std::endl;
        orderProducts();
    }
};

class StoreDecorator : public Store // Decorator class for the stores, not implemented due to time constraints
{
    std::string storeName;
    std::unique_ptr<Store> decorator;
public:
    StoreDecorator(std::unique_ptr<Store> decorator, std::string storeName) : decorator(std::move(decorator)), storeName(storeName) {};

    std::string setStoreName() override
    {
        return storeName;
    }
};

class StoreFactory // Factory class to create the stores based upon users selection
{
public:
    static Store* createStore(StoreSize storeSize)
    {
        switch (storeSize)
        {
        case StoreSize::Small:
            return new TreforestStore(); // Treforest
        case StoreSize::Medium:
            return new PontypriddStore(); // Pontypridd
        case StoreSize::Large:
            return new CardiffStore(); // Cardiff
        }
    }
};

int main() // Main function program begins and ends here. Allows users to select which store they wish to browse
{
    bool menuLoop = true;
    int16_t uint16_menuInput = 0;
    StoreFactory storeFactory;

    while (menuLoop)
    {
        std::cout << "Please select store to browse." << std::endl;
        std::cout << "1 - Treforest" << std::endl;
        std::cout << "2 - Pontypridd" << std::endl;
        std::cout << "3 - Cardiff" << std::endl;
        std::cout << "0 - Quit" << std::endl;
        std::cout << "Selection: ";
        std::cin >> uint16_menuInput;
        std::cout << std::endl;
        if (std::cin.fail())
        {
            std::cout << "Invalid input, please enter a valid integer value..." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            if (uint16_menuInput == 1 || uint16_menuInput == 2 || uint16_menuInput == 3)
            {
                menuLoop = false;
                StoreSize selectedSize = static_cast<StoreSize>(uint16_menuInput);
                Store* store = storeFactory.createStore(selectedSize);
                store->storeMainMenu();
            }
            else if (uint16_menuInput < 0 || uint16_menuInput > 3)
            {
                std::cout << "Invalid choice, please enter number between 0 and 3..." << std::endl;
            }
            else if (uint16_menuInput == 0)
            {
                std::cout << "Exiting program..." << std::endl;
                menuLoop = false;
                return 0;
            }
        }
    }
}
