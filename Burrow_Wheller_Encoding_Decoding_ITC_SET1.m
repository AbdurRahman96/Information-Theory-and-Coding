%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Burrowwheller transform is a compression tecnique that rearraanges a
% given string runs of similar character

%NOTE: The encoded sequence will have an extra '$' sign which is used in
%decoding. 

%Author: Abdur Rahman Mohamed Ismail.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;
clear all;
close all;
prompt='Enter the string to be encoded';
str=input(prompt,'s');
str=[str';'$']';
N=length(str);
%%%%%%%%%%%%%%%%%%%%%%
% Creating the matrix with shifted code words
str1=circshift(str,N-1);
m=zeros(N,N);
for i=1:N
m(i,:)=circshift(str1,i);
end
%%%%%%%%%%%%%%%%%%%%%%%
% Sorting the entire matrix
g=sortrows(m);
%%%%%%%%%%%%%%%%%%%%%%
%Extracting the codeed string 
code=g(1:N,N);
%%%%%%%%%%%%%%%%%%%%%%%
disp("The encoded string is");
disp(char(g(:,N)));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% DECODING PART

prompt='Enter the string to be decoded ( JUST ENTER THE ABOVE ENCODED STRING)';
str_d=input(prompt,'s');
N_d=length(str_d);
m_d=zeros(N_d,N_d);
%str=sort(str);
%%%%%% Pad encoded string and sort for N times
for i=N:-1:1
m_d(:,i)=str_d;
m_d=sortrows(m_d);
end

disp("The decoded string is");
disp(char(m_d(1,:)));





