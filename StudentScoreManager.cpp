#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Cấu trúc lưu thông tin sinh viên
struct Student {
    int id;
    string name;
    float score;
};

// Lớp quản lý bảng điểm
class ScoreBoard {
private:
    vector<Student> students; // Danh sách sinh viên
    int nextId;               // ID tự động tăng cho mỗi sinh viên

public:
    // Khởi tạo
    ScoreBoard() : nextId(1) {}

    // Hàm thêm sinh viên
    void addStudent(const string& name, float score) {
        students.push_back({nextId++, name, score});
        cout << "✅ Đã thêm sinh viên: " << name << " với điểm số: " << score << endl;
    }

    // Hiển thị danh sách sinh viên
    void displayStudents() {
        cout << "\n📋 Danh sách sinh viên:\n";
        cout << left << setw(5) << "ID" << setw(20) << "Tên" << setw(10) << "Điểm" << endl;
        cout << string(35, '-') << endl;
        for (const auto& student : students) {
            cout << left << setw(5) << student.id << setw(20) << student.name << setw(10) << student.score << endl;
        }
    }

    // Tính điểm trung bình
    void calculateAverageScore() {
        if (students.empty()) {
            cout << "⚠️ Không có sinh viên nào để tính điểm trung bình.\n";
            return;
        }
        float totalScore = 0;
        for (const auto& student : students) {
            totalScore += student.score;
        }
        cout << "📊 Điểm trung bình của lớp: " << totalScore / students.size() << endl;
    }

    // Tìm sinh viên có điểm cao nhất
    void findTopStudent() {
        if (students.empty()) {
            cout << "⚠️ Không có sinh viên nào để tìm.\n";
            return;
        }
        const Student* topStudent = &students[0];
        for (const auto& student : students) {
            if (student.score > topStudent->score) {
                topStudent = &student;
            }
        }
        cout << "🏆 Sinh viên có điểm cao nhất: " << topStudent->name
             << " với điểm số: " << topStudent->score << endl;
    }
};

int main() {
    ScoreBoard scoreboard;
    int choice;

    do {
        cout << "\n===== BẢNG ĐIỂM SINH VIÊN =====\n";
        cout << "1. Thêm sinh viên\n";
        cout << "2. Hiển thị danh sách sinh viên\n";
        cout << "3. Tính điểm trung bình\n";
        cout << "4. Tìm sinh viên điểm cao nhất\n";
        cout << "0. Thoát\n";
        cout << "Chọn: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            float score;
            cout << "Nhập tên sinh viên: ";
            cin.ignore(); // Xóa bộ đệm trước khi nhập chuỗi
            getline(cin, name);
            cout << "Nhập điểm số: ";
            cin >> score;
            scoreboard.addStudent(name, score);
            break;
        }
        case 2:
            scoreboard.displayStudents();
            break;
        case 3:
            scoreboard.calculateAverageScore();
            break;
        case 4:
            scoreboard.findTopStudent();
            break;
        case 0:
            cout << "👋 Tạm biệt!\n";
            break;
        default:
            cout << "❌ Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    } while (choice != 0);

    return 0;
}