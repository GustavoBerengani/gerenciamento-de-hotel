# 🏨 - Sistema de Gerenciamento de Hotel 

Projeto acadêmico desenvolvido em C/C++ pelos integrantes:  
**Gustavo, Henrique, Thomas e Thales**  
📅 Data: 16/06/2024  

---

## 📋 Descrição
Este programa é um **sistema de gerenciamento de reservas de um hotel**.  
Ele simula o funcionamento básico de um hotel.

O sistema permite realizar operações de **reserva, cancelamento, check-in, check-out, visualização de hóspedes e cálculo de taxas de ocupação**.

---

## ⚙️ Funcionalidades

- **Visualizar mapa dos apartamentos** (ocupado, reservado, livre)  
- **Reservar quarto** com cadastro de hóspede  
- **Cancelar reserva**  
- **Check-in** de hóspede com ou sem reserva  
- **Check-out** liberando o quarto  
- **Visualizar taxas** de ocupação e reservas do hotel  
- **Consultar status e dados do hóspede** em determinado quarto  

---

## 🗂️ Estrutura do Sistema

- `struct stapto` → estrutura que armazena os dados de cada hóspede (nome, CPF, endereço, telefone, email e status do quarto).  
- `Hotel[21][15]` → matriz que representa o mapa do hotel (20 andares × 14 quartos).  
- Funções auxiliares:  
  - `fMapa()` → exibe o mapa do hotel.  
  - `fDadosHospede()` → mostra os dados do hóspede em determinado quarto.  
  - `fVerifica()` → valida CPF na reserva e check-in.  
  - `fclear()` → limpa o buffer de entrada.  

---

## 🖥️ Menu Principal

O sistema oferece as seguintes opções no menu:

1. Disposição de Apartamentos  
2. Reserva  
3. Cancelamento  
4. Check-In (com reserva)  
5. Check-In (sem reserva)  
6. Check-Out  
7. Visualizar Taxa de Reserva e Ocupação  
8. Visualizar Status e Dados do Hóspede  
9. Sair  

---

## 🏷️ Legenda do Mapa

- `.` → Quarto livre  
- `R` → Reservado  
- `O` → Ocupado  

---

## 🚀 Como executar

1. Compile o código:
   ```bash
   g++ hotel.cpp -o hotel
