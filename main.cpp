#include <iostream>  
#include <vector>  
#include <string>  
#include <limits>

class Task {  
public:  
    std::string description;  
    bool completed;  
  
    Task(const std::string& desc) : description(desc), completed(false) {}  
};  
  
class TaskList {  
private:  
    std::vector<Task> tasks;  
  
public:  
    void addTask(const std::string& description) {  
        tasks.emplace_back(description);  
    }  
  
    void viewTasks() {  
        std::cout << "任务清单：" << std::endl;  
        for (size_t i = 0; i < tasks.size(); ++i) {  
            std::cout << (i + 1) << ". " << tasks[i].description;  
            if (tasks[i].completed) {  
                std::cout << " (已完成)";  
            }  
            std::cout << std::endl;  
        }  
    }  
  
    void completeTask(size_t index) {  
        if (index >= 1 && index <= tasks.size()) {  
            tasks[index - 1].completed = true;  
            std::cout << "任务 " << index << " 已标记为完成。" << std::endl;  
        } else {  
            std::cout << "错误的任务编号。" << std::endl;  
        }  
    }  
  
    void deleteTask(size_t index) {  
        if (index >= 1 && index <= tasks.size()) {  
            tasks.erase(tasks.begin() + index - 1);  
            std::cout << "任务 " << index << " 已被删除。" << std::endl;  
        } else {  
            std::cout << "错误的任务编号。" << std::endl;  
        }  
    }  
};  
  
void displayMenu() {  
    std::cout << "任务清单管理程序" << std::endl;  
    std::cout << "1. 添加任务" << std::endl;  
    std::cout << "2. 查看任务" << std::endl;  
    std::cout << "3. 完成任务" << std::endl;  
    std::cout << "4. 删除任务" << std::endl;  
    std::cout << "5. 退出程序" << std::endl;  
    std::cout << "请输入您的选择：";  
}  
  
int main() {  
    TaskList taskList;  
    int choice;  
    while (true) {  
        displayMenu();  
        std::cin >> choice;  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区  
        switch (choice) {  
            case 1: {  
                std::string description;  
                std::cout << "请输入任务描述: ";  
                std::getline(std::cin, description);  
                taskList.addTask(description);  
                break;  
            }  
            case 2:  
                taskList.viewTasks();  
                break;  
            case 3: {  
                size_t index;  
                std::cout << "请输入要完成的任务编号: ";  
                std::cin >> index;  
                taskList.completeTask(index);  
                break;  
            }  
            case 4: {  
                size_t index;  
                std::cout << "请输入要删除的任务编号: ";  
                std::cin >> index;  
                taskList.deleteTask(index);  
                break;  
            }  
            case 5:  
                return 0; // 退出程序  
            default:  
                std::cout << "无效的选择，请重新选择。" << std::endl;  
        }  
    }  
    return 0;  
}