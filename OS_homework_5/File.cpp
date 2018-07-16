//
// Created by 王予亮 on 2018/5/24.
//
#include "File.h"
#include<iostream>
_FILE::_FILE() {
    cout<<"FILE constructed"<<endl;
    this->ramSize = 500;
    _block temp;
    temp.Flag = "empty";
    temp.Length = 500;
    temp.startIndex = 0;
    blockList.push_back(temp);
}
_FILE::_FILE(int size){
    cout<<"Free Table constructed"<<endl;
    this->ramSize = size;
    _block temp;
    temp.Flag = "empty";
    temp.Length = size/2;//空闲块数
    temp.startIndex = 0;
    blockList.push_back(temp);
}
void _FILE::LoadFILE(int fileSize, string fileName) {
    //first: search appropriate block
    bool ifFirstInsert = true;
    cout<<"存入文件："<<fileName<<",文件大小："<<fileSize<<"K,需要块数："<<fileSize/2 + fileSize%2<<endl;
    for(int i = 0;i<blockList.size();i++){
        if(blockList.at(i).Flag == "empty"){
            if(fileSize<=blockList.at(i).Length) {
                _file temp;
                temp.startIndex = blockList.at(i).startIndex;
                temp.Length = fileSize / 2 + fileSize % 2;
                temp.fileName = fileName;
                if(!ifFirstInsert){
                    temp.next = -1;
                    fileList[fileList.size()-1].next = temp.startIndex;
                }
                else temp.next = -1;
                fileList.push_back(temp);
                blockList.at(i).startIndex += fileSize / 2 + fileSize % 2;
                blockList.at(i).Length -= fileSize / 2 + fileSize % 2;
                return;
            }
            else if(fileSize>blockList.at(i).Length){
                if(ifFirstInsert) {
                    //int templen = blockList.at(i).Length;
                    _file temp;
                    temp.startIndex = blockList.at(i).startIndex;
                    temp.Length = blockList.at(i).Length;
                    temp.fileName = fileName;
                    temp.next = 0;
                    //to the filetable
                    fileList.push_back(temp);
                    fileSize -= temp.Length;

                    blockList.erase(blockList.begin()+i);
                    ifFirstInsert = false;
                }
                else{
                    _file temp;
                    temp.startIndex = blockList.at(i).startIndex;
                    temp.Length = blockList.at(i).Length;
                    temp.fileName = fileName;
                    temp.next = 0;
                    fileList[fileList.size()-1].next = blockList.at(i).startIndex;
                    fileList.push_back(temp);
                    fileSize -= temp.Length;
                    blockList.erase(blockList.begin()+i);
                }
            }
        }
    }

}
void _FILE::DeleteFile(string fileName) {
    for(int i = 0;i<fileList.size();i++) {
        if (fileList[i].fileName == fileName) {
            int j = fileList[i].next;
            _block temp;
            temp.Length = fileList[i].Length;
            temp.startIndex = fileList[i].startIndex;
            temp.Flag = "empty";
            blockList.push_back(temp);
            fileList.erase(fileList.begin() + i);//delete the element in fileList
            if(j == -1) break;
            else i = j;
        }
    }

    cout<<"删除文件："<<fileName<<endl;
//    }
//    for(int i=0;i<blockList.size();i++){
//        if(start+len==blockList[i].startIndex){
//            blockList[i].startIndex -= len;
//        }
//    }
}
void _FILE::showBlockList() {
    cout<<endl<<"[Free Table]"<<endl;
    for(int i = 0;i<blockList.size();i++){
        cout<<"起始地址："<<blockList.at(i).startIndex<<",长度："<<blockList.at(i).Length<<"块"<<endl;
    }
    cout<<"[End of Free Table]"<<endl<<endl;
}
void _FILE::showFileList() {
    cout<<endl<<"[File Table]"<<endl;
    if(fileList.empty()){
        cout<<"[End of File Table]"<<endl;
        return;
    }
    for(int i = 0;i<fileList.size();i++){
        cout<<"起始地址："<<fileList.at(i).startIndex<<",长度："<<fileList.at(i).Length<<"块, 文件名："<<fileList.at(i).fileName<<"，下址："<<fileList.at(i).next<<endl;
    }
    cout<<"[End of File Table]"<<endl<<endl;
}

void _FILE::defrag() {
    cout<<endl<<"[defrag]"<<endl;
    if(blockList.empty()||blockList.size()==1) return;
    int i = 0, j = 0;
    //first: sort the free table
    sort(blockList.begin(),blockList.end(),compare);
    //then: merge
    while(i<blockList.size()-1){
        while(blockList.at(i).startIndex+blockList.at(i).Length==blockList.at(i+1).startIndex) {
            //cout<<blockList.size()<<" ["<<i<<"]("<<j++<<") "<<endl;
            int temp = blockList.at(i).Length;
            blockList.erase(blockList.begin() + i);
            blockList.at(i).startIndex -= temp;
            blockList.at(i).Length += temp;
            if(i >= blockList.size()-1) break;
        }
        i++;
    }
}
bool _FILE::compare(_block a, _block b) {
    return a.startIndex<b.startIndex;
}