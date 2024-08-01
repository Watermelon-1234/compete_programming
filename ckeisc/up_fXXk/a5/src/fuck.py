# 檔案名稱
filename = "my_file.txt"

# 打開檔案以寫入模式
with open(filename, "w") as file:
    # 寫入第一行
    file.write("200000 1000000000\n")

    # 寫入第二行
    for i in range(1, 200001):
        file.write("1000000000")
        file.write(" ");
    file.write("\n")

print(f"已成功寫入 {filename}")
