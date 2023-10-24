#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Hora{
    private:
    int hora, min;

    public:
     // Construtor
    Hora(int _hora, int _min) {
        this->hora = _hora;
        this->min = _min;
    }

    void setHora(int _hora) {
        this->hora = _hora;
    }

    void setMin(int _min) {
        this->min = _min;
    }

    int getHora() {
        return this->hora;
    }

    int getMin() {
        return this->min;
    }

};

class Data {
    private:
    int dia;
    int mes;
    int ano;

    public:
    //Construtor
     Data(int _dia, int _mes, int _ano) 
        : dia(_dia), mes(_mes), ano(_ano) {}

    //Setters
    void setDia(int _dia){
        this->dia = _dia;
    }

    void setMes(int _mes){
        this->mes = _mes;
    }

    void setAno(int _ano){
        this->ano = _ano;
    }

    //Getters
    int getDia(){
        return this->dia;
    }

    int getMes(){
        return this->mes;
    }

    int getAno(){
        return this->ano;
    }

    
    
};

class Paciente {
    private:
    string cpf;
    string nomePaciente;
    Data dtNascimento;

    public:
    //Construtor
     Paciente(string _nomePaciente, string _cpf,  Data _dtNascimento)
        : cpf(_cpf), nomePaciente(_nomePaciente), dtNascimento(_dtNascimento) {}

    //Setters
    void setCpf(string _cpf){
        this->cpf = _cpf;
    }

    void setNomePaciente(string _nomePaciente){
        this->nomePaciente = _nomePaciente;
    }

    //Getters
    string getCpf(){
        return this->cpf;
    }

    string getNomePaciente(){
        return this->nomePaciente;
    }

    Data getDtNascimento(){
        return this->dtNascimento;
    }

    //Vou passar um vector como refencia para que seja adicionado nele
    void incluir(vector<Paciente> &pacientes, Paciente p){
        pacientes.push_back(p);
    }

    void alterar(Paciente &paciente, string nome){
        paciente.setNomePaciente(nome);

    }

    void alterar(Paciente &paciente, int dia, int mes, int ano){
        paciente.alterarDataNascimento(dia, mes, ano);
    }

    void alterarDataNascimento(int dia, int mes, int ano) {
        dtNascimento.setDia(dia);
        dtNascimento.setMes(mes);
        dtNascimento.setAno(ano);
    }

};


class Medico {
    private:
    string crm;
    string nomeMedico;
    string especialidade;

    public:
    Medico(string _nomeMedico , string _crm, string _especialidade)
        : crm(_crm), nomeMedico(_nomeMedico), especialidade(_especialidade) {}

    //Setters
    void setCrm(string _crm){
        this->crm = _crm;
    }

    void setNomeMedico(string _nomeMedico){
        this->nomeMedico = _nomeMedico;
    }

    void setEspecialidade(string _especialidade){
        this->especialidade = _especialidade;
    }

    //Getters
    string getCrm(){
        return this->crm;
    }

    string getNomeMedico(){
        return this->nomeMedico;
    }

    string getEspecialidade(){
        return this->especialidade;
    }

    void incluir(vector<Medico> &medicos, Medico medico){
        medicos.push_back(medico);
    }

    void alterarNomeMedico(Medico &medico, string nome){
        medico.setNomeMedico(nome);
    }

    void alterarEspecialidadeMedico(Medico &medico, string especialidade){
        medico.setEspecialidade(especialidade);
    }
    
};


class Consulta{
    private:
    char realizada; 
    Data data;
    Hora hora;
    string duracao;
    string convenio;
    Paciente paciente;
    Medico medico;


    public:
      //Construtor
     Consulta(Paciente _paciente, Medico _medico, Data _data, Hora _hora, string _duracao, string _convenio, char _realizada)
        : paciente(_paciente), medico(_medico), data(_data), hora(_hora), duracao(_duracao), convenio(_convenio), realizada(_realizada) {}
     
     // Getters
    char getRealizada() { return this->realizada; }
    Data getData() { return this->data; }
    Hora getHora() { return this->hora; }
    string getDuracao() { return this->duracao; }
    string getConvenio() { return this->convenio; }
    Paciente getPaciente() { return this->paciente; }
    Medico getMedico() { return this->medico; }

    // Setters
    void setRealizada(char _realizada) { this->realizada = _realizada; }
    void setData(Data _data) { this->data = _data; }
    void setData(Hora _hora) { this->hora = _hora; }
    void setDuracao(string _duracao){this->duracao = _duracao; }
    void setConvenio(string _convenio) { this->convenio = _convenio; }
    void setPaciente(Paciente _paciente) { this->paciente = _paciente; }
    void setMedico(Medico _medico) { this->medico = _medico; }

    void incluir(vector<Consulta> &consultas, Consulta consulta){
        consultas.push_back(consulta);
    }

    int verificacaoConsultaRepetida(vector<Consulta> consultas, Consulta novaConsulta) {
        int diaNc, mesNc, anoNc, horaNc, minNc;
        diaNc = novaConsulta.getData().getDia();
        mesNc = novaConsulta.getData().getMes();
        anoNc = novaConsulta.getData().getAno();
        horaNc = novaConsulta.getHora().getHora();
        minNc = novaConsulta.getHora().getMin();

        for (auto consulta : consultas) {
            int dia, mes, ano;
            dia = consulta.getData().getDia();
            mes = consulta.getData().getMes();
            ano = consulta.getData().getAno();

            int hora, min;
            hora = consulta.getHora().getHora();
            min = consulta.getHora().getMin();
            
            if(consulta.getPaciente().getCpf() == novaConsulta.getPaciente().getCpf()){
                if (dia == diaNc && mes == mesNc && ano == anoNc && hora == horaNc && min == minNc) {
                    // A nova consulta é repetida.
                    return 0;
                }
            }
            
        }
        // Não foi encontrada uma consulta repetida.
        return 1;
}
    
    
};

class VerificaDados{
    private:
    int verificaTamanhoCpf;
    int verificaDigito;
    int verificaCpfCadastrado;
    int verificaData;
    int verificaCrm;
    int verificaHora;
    int verificaMinuto;

    public:
    int getVerificaTamanhoCpf(){
        return this->verificaTamanhoCpf;
    }

    int getVerificaData(){
        return this->verificaData;
    }

    int getVerificaDigito(){
        return this->verificaDigito;
    }

    int getVerificaCpfCadastrado(){
        return this->verificaCpfCadastrado;
    }

    int getVerificaCrmCadastrado(){
        return this->verificaCrm;
    }

    int getVerificaHora(){
        return this->verificaHora;
    }

    VerificaDados(){

    }

    int verificacaoCpf(vector<Paciente> pacientes, string cpf){
        // 1 - Verifica o tamanho do CPF
        if(cpf.length() == 11){
            this->verificaTamanhoCpf = 1;
        }else{
            this->verificaTamanhoCpf = 0;
        }

        // 2 - Verifica se so foram passados numeros
        for(int i = 0; i < cpf.length(); i++){
            if(isdigit(cpf[i])){
                this->verificaDigito = 1;
            }else{
                this->verificaDigito = 0;
                break;
            }
        }

        //3 - Verifica se já possui cpf cadastrado
        for(int i = 0; i < pacientes.size() ; i++){
            if(pacientes[i].getCpf() == cpf){
                this->verificaCpfCadastrado = 0;
                break;
            }else{
                this->verificaCpfCadastrado = 1;
            }
        }

        //Retorna um feedback se tá tudo certo
        if(this->verificaTamanhoCpf && this->verificaDigito && this->verificaCpfCadastrado){
            return 1;
        }
        return 0;
       
    }

    int verificacaoData(int dia, int mes, int ano){
    if (ano >= 1900 && ano <= 2023) {
        if (mes >= 1 && mes <= 12) {
            if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia >= 1 && dia <= 31)) {
             this->verificaData = 1;
            } else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia >= 1 && dia <= 30)) {
                this->verificaData = 1;
            } else if (mes == 2) {
                if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
                    if (dia >= 1 && dia <= 29) {
                        this->verificaData = 1;
                    } else {
                        this->verificaData = 0;
                    }
                } else {
                    if (dia >= 1 && dia <= 28) {
                        this->verificaData = 1;
                    } else {
                        this->verificaData = 0;
                    }
                }
            } else {
                this->verificaData = 0;
            }
        } else {
            this->verificaData = 0;
        }
    } else {
        this->verificaData = 0;
    }

        //Retorna o feedback
        if(this->verificaData){
            return 1;
        }

        return 0;
    }

    int vericacaoCrm(vector<Medico> medicos, string crm){
        for(int i = 0; i<medicos.size(); i++){
            if(medicos[i].getCrm() == crm){
                return 0;
            }
        }
        return 1;
    }

    int verificacaoHora(int hora, int minuto){
        if(hora >= 0 && hora <= 23 ){
            this->verificaHora = 1;
        }else{
            this->verificaHora = 0;
        }

        if(minuto >= 0 && minuto <= 59 ){
            this->verificaMinuto = 1;
        }else{
            this->verificaMinuto = 0;
        }

        if(this->verificaHora == 1 && this->verificaMinuto == 1){
            return 1;
        }
        return 0;
    }

};



int localizarPorCpf(vector<Paciente> pacientes, string cpfProcurado){
    for(int i = 0; i<pacientes.size(); i++){
        if(pacientes[i].getCpf() == cpfProcurado){
            return i;
        }
    }
    return -1;
}

int localizarPorCrm(vector<Medico> medicos, string crmProcurado){
    for(int i = 0; i<medicos.size(); i++){
        if(medicos[i].getCrm() == crmProcurado){
            return i;
        }
    }
    return -1;
}

int main(){
    
    int opcao;
    int opcaoSubMenu;
    vector <Paciente> pacientes;
    vector <Medico> medicos;
    vector <Consulta> consultas;
    VerificaDados verificacao;
    

    do{
        cout << ">>> BEM-VINDO(A) A CLINICA SEM DODOI <<<" << endl;
        cout << "[1] GESTAO DE PACIENTES " << endl;
        cout << "[2] GESTAO DE MEDICOS " << endl;
        cout << "[3] GESTAO DE CONSULTAS " << endl;
        cout << "[0] SAIR " << endl;
        cin >> opcao;
        cin.ignore();

        switch(opcao){
            case 0:
            break;
            //REFATORAR ESSE MENU 
            case 1:
            do{
                cout << ">>> PACIENTES <<<" << endl;
                cout << "[1] INCLUIR" << endl;
                cout << "[2] EXCLUIR" << endl;
                cout << "[3] ALTERAR" << endl;
                cout << "[4] LISTAR" << endl;
                cout << "[5] LOCALIZAR" << endl;
                cout << "[0] SAIR" << endl;
                cin >> opcaoSubMenu;
                cin.ignore();

                switch(opcaoSubMenu){
                    case 0:
                    break;

                    case 1:
                        {   system("cls");
                            string nome, cpf;
                            int dia, mes, ano;

                            cout << "------- INSERIR PACIENTE -------" << endl;
                            cout << "Informe o nome do paciente: " << endl;
                            getline(cin,nome);
                            cout << "Informe o CPF do paciente (apenas digitos): " << endl;
                            getline(cin,cpf);
                            /*
                                Verificação do CPF:
                                1 - Verificar se o CPF tem 11 digitos, considerando
                                    que seja passando apenas números.
                                2 - Verificar se foram passandos apenas digitos.
                                3 - Verificar se o paciente já está inserido.
                            */

                            if(verificacao.verificacaoCpf(pacientes, cpf)){
                                cout << "Informe o dia do seu nascimento: " << endl;
                                cin >> dia;
                                cout << "Informe o mes do seu nascimento: " << endl;
                                cin >> mes;
                                cout << "Informe o ano do seu nascimento: " << endl;
                                cin >> ano;

                                if(verificacao.verificacaoData(dia, mes, ano)){
                                    Data data(dia, mes, ano);
                                    Paciente paciente(nome, cpf, data);
                                    paciente.incluir(pacientes, paciente);
                                    system("cls");
                                    cout << "Paciente inserido com sucesso!" << endl;
                                }else{
                                    cout << "Data invalida..." << endl;
                                }

                            }else{
                                //Mostra um feedback do que foi preenchido errado
                                if(!verificacao.getVerificaTamanhoCpf()){
                                    cout << "1 - CPF com digitos a mais ou a menos" << endl;
                                }

                                if(!verificacao.getVerificaDigito()){
                                    cout << "2 - CPF com digitos invalidos" << endl;
                                }

                                if(!verificacao.getVerificaCpfCadastrado()){
                                    cout << "3 - CPF ja cadastrado" << endl;
                                }
                            }
                            cout << "----------------------------------" << endl;
                            
                        }
                    break;

                    case 2:
                        {
                            system("cls");
                            string cpfProcurado;
                            int indice;

                            cout << "------- EXCLUIR PACIENTE -------" << endl;
                            cout << "Informe o CPF do paciente: " << endl;
                            getline(cin, cpfProcurado);
                            indice = localizarPorCpf(pacientes, cpfProcurado);

                            if(indice != -1){
                                cout << "Paciente de nome: " << pacientes[indice].getNomePaciente() << " excluido." << endl;
                                pacientes.erase(pacientes.begin() + indice);
                            }else{
                                cout << "Paciente nao encontrado..." << endl;
                            }
                             cout << "----------------------------------" << endl;

                        }
                    break;

                    case 3:
                        { 
                            system("cls");
                            string cpfProcurado;
                            int indice;
                            int escolha;
                            int dia, mes, ano;
                            string nome;

                            cout << "------- ALTERANDO PACIENTE -------" << endl;
                            cout << "Informe o CPF do paciente: " << endl;
                            getline(cin, cpfProcurado);
                            indice = localizarPorCpf(pacientes, cpfProcurado);
                            if(indice != -1){
                                cout << "Nome: " << pacientes[indice].getNomePaciente() << endl;
                                cout << "CPF: " << pacientes[indice].getCpf() << endl;
                                cout << "Data de Nascimento: " << pacientes[indice].getDtNascimento().getDia();
                                cout << " / " << pacientes[indice].getDtNascimento().getMes();
                                cout << " / " << pacientes[indice].getDtNascimento().getAno() << endl;

                                cout << "----------------------------------------------------" << endl;

                                cout << "Deseja alterar o nome desse paciente: 1-SIM / 2-NAO" << endl;
                                cin >> escolha;
                                cin.ignore();

                                if(escolha == 1){
                                    cout << "Informe o nome do paciente: " << endl;
                                    getline(cin, nome);
                                    pacientes[indice].alterar(pacientes[indice], nome);
                                    cout << "Nome alterado com sucesso!" << endl;
                                }else if(escolha != 1 && escolha != 2){
                                    cout << "Opcao invalida!" << endl;
                                    break;
                                }

                                cout << "Deseja alterar a data de nascimento  desse paciente: 1-SIM / 2-NAO" << endl;
                                cin >> escolha;
                                cin.ignore();

                                if(escolha == 1){
                                    cout << "Informe o dia do seu nascimento: " << endl;
                                    cin >> dia;
                                    cout << "Informe o mes do seu nascimento: " << endl;
                                    cin >> mes;
                                    cout << "Informe o ano do seu nascimento: " << endl;
                                    cin >> ano;

                                    if(verificacao.verificacaoData(dia, mes, ano)){
                                        pacientes[indice].alterar(pacientes[indice],dia, mes, ano );
                                        cout << "Data alterada com sucesso!" << endl;
                                    }else{
                                        cout << "Data invalida..." << endl;
                                    }

                                }else if(escolha != 1 && escolha != 2){
                                    cout << "Opcao invalida!" << endl;
                                }

                            }else{
                                cout << "Paciente nao encontrado..." << endl;
                            }
                            cout << "----------------------------------" << endl;

                        }
                    break;

                    case 4:
                        system("cls");
                        cout << "------- LISTANDO PACIENTES -------" << endl;
                        for(auto paciente : pacientes){
                            cout << "----------------------------------" << endl;
                            cout << "Nome: " << paciente.getNomePaciente() << endl;
                            cout << "CPF: " << paciente.getCpf() << endl;
                            cout << "Data de Nascimento: " << paciente.getDtNascimento().getDia();
                            cout << " / " << paciente.getDtNascimento().getMes();
                            cout << " / " << paciente.getDtNascimento().getAno() << endl;
                        }
                        cout << "----------------------------------" << endl;
                    break;

                    case 5:
                        {
                        system("cls");
                        string cpfProcurado;
                        int indice;

                        cout << "------- LOCALIZAR PACIENTE -------" << endl;
                        cout << "Informe o CPF do paciente: " << endl;
                        getline(cin, cpfProcurado);
                        indice = localizarPorCpf(pacientes, cpfProcurado);
                        if(indice != -1){
                            cout << "Nome: " << pacientes[indice].getNomePaciente() << endl;
                            cout << "CPF: " << pacientes[indice].getCpf() << endl;
                            cout << "Data de Nascimento: " << pacientes[indice].getDtNascimento().getDia();
                            cout << " / " << pacientes[indice].getDtNascimento().getMes();
                            cout << " / " << pacientes[indice].getDtNascimento().getAno() << endl;
                        }else{
                            cout << "Paciente nao encontrado..." << endl;
                        }
                        cout << "----------------------------------" << endl;

                        }
                    break;

                    default:
                        system("cls");
                        cout << "Opcao invalida! " << endl;
                    break;
                }

            }while(opcaoSubMenu != 0);
            break;

            case 2:
            do{
                cout << ">>> MEDICOS <<<" << endl;
                cout << "[1] INCLUIR" << endl;
                cout << "[2] EXCLUIR" << endl;
                cout << "[3] ALTERAR" << endl;
                cout << "[4] LISTAR" << endl;
                cout << "[5] LOCALIZAR" << endl;
                cout << "[0] SAIR" << endl;
                cin >> opcaoSubMenu;
                cin.ignore();

                switch(opcaoSubMenu){
                    case 0:
                    break;

                    case 1:
                        {
                            system("cls");
                            string nomeMedico, crm, especialidade ;

                            cout << "------- INSERIR MEDICO -------" << endl;
                            cout << "Informe o nome do Medico: " << endl;
                            getline(cin,nomeMedico);
                            cout << "Informe o CRM do medico" << endl;
                            getline(cin,crm);
                            cout << "Informe a especialidade do medico" << endl;
                            getline(cin,especialidade);

                            if(verificacao.vericacaoCrm(medicos, crm)){
                                Medico novoMedico (nomeMedico, crm, especialidade);
                                novoMedico.incluir(medicos, novoMedico);
                                system("cls");
                                cout << "Medico inserido com sucesso!" << endl;
                            }else{
                                cout << "Medico ja inserido..." << endl;
                            }
                        }
                    break;

                    case 2:
                        {
                            system("cls");
                            string crmProcurado;
                            int indice;

                            cout << "------- EXCLUIR PACIENTE -------" << endl;
                            cout << "Informe o crm do paciente: " << endl;
                            getline(cin, crmProcurado);
                            indice = localizarPorCrm(medicos, crmProcurado);

                            if(indice != -1){
                                cout << "Medico de nome: " << medicos[indice].getNomeMedico() << " excluido." << endl;
                                medicos.erase(medicos.begin() + indice);
                            }else{
                                cout << "Medico nao encontrado..." << endl;
                            }
                             cout << "----------------------------------" << endl;
                        }
                    break;

                    case 3:
                        {
                            system("cls");
                            string crmProcurado, nome, especialidade;
                            int indice, escolha;

                            cout << "------- ALTERANDO MEDICO -------" << endl;
                            cout << "Informe o CRM do MEDICO: " << endl;
                            getline(cin, crmProcurado);
                            indice = localizarPorCrm(medicos, crmProcurado);
                            if(indice != -1){
                                cout << "Nome: " << medicos[indice].getNomeMedico() << endl;
                                cout << "CRM: " << medicos[indice].getCrm() << endl;
                                cout << "Especialidade: " << medicos[indice].getEspecialidade() << endl;

                                cout << "----------------------------------------------------" << endl;

                                cout << "Deseja alterar o nome desse medico: 1-SIM / 2-NAO" << endl;
                                cin >> escolha;
                                cin.ignore();

                                if(escolha == 1){
                                    cout << "Informe o nome do medico: " << endl;
                                    getline(cin, nome);
                                    medicos[indice].alterarNomeMedico(medicos[indice], nome);
                                    cout << "Nome alterado com sucesso!" << endl;
                                }else if(escolha != 1 && escolha != 2){
                                    cout << "Opcao invalida!" << endl;
                                    break;
                                }

                                cout << "Deseja alterar a especilidade desse medico: 1-SIM / 2-NAO" << endl;
                                cin >> escolha;
                                cin.ignore();

                                if(escolha == 1){
                                    cout << "Informe a especialidade: " << endl;
                                    getline(cin, especialidade);
                                    medicos[indice].alterarEspecialidadeMedico(medicos[indice], especialidade);
                                    cout << "Especialidade alterada com sucesso!" << endl;
                                }else if(escolha != 1 && escolha != 2){
                                    cout << "Opcao invalida!" << endl;
                                }

                            }else{
                                cout << "Paciente nao encontrado..." << endl;
                            }
                            cout << "----------------------------------" << endl;
                        }
                    break;

                    case 4:
                         system("cls");
                         cout << "------- LISTANDO MEDICOS -------" << endl;
                        for(auto medico : medicos){
                            cout << "----------------------------------" << endl;
                            cout << "Nome: " << medico.getNomeMedico() << endl;
                            cout << "CRM: " << medico.getCrm() << endl;
                            cout << "Especialidade: " << medico.getEspecialidade() << endl;
                        }
                         cout << "----------------------------------" << endl;
                    break;

                    case 5:
                        {
                            system("cls");
                            string crmProcurado;
                            int indice;

                            cout << "------- LOCALIZAR MEDICO -------" << endl;
                            cout << "Informe o CRM do Medico: " << endl;
                            getline(cin, crmProcurado);
                            indice = localizarPorCrm(medicos, crmProcurado);
                            if(indice != -1){
                                cout << "----------------------------------" << endl;
                                cout << "Nome: " << medicos[indice].getNomeMedico() << endl;
                                cout << "CRM: " << medicos[indice].getCrm() << endl;
                                cout << "Especialidade: " << medicos[indice].getEspecialidade() << endl;
                            }else{
                                cout << "Medico nao encontrado..." << endl;
                            }
                            cout << "----------------------------------" << endl;
                        }
                    break;

                    default:
                        cout << "Opcao invalida! " << endl;
                    break;
                }


            }while(opcaoSubMenu != 0);
            break;

            case 3:
                do{
                cout << ">>> CONSULTAS <<<" << endl;
                cout << "[1] INCLUIR CONSULTA" << endl;
                cout << "[2] EXCLUIR CONSULTA" << endl;
                cout << "[3] ALTERAR CONSULTA" << endl;
                cout << "[4] LISTAR CONSULTAS" << endl;
                cout << "[0] SAIR" << endl;
                cin >> opcaoSubMenu;
                cin.ignore();

                switch(opcaoSubMenu){
                    case 0:
                    break;

                    case 1:
                        { /* Alessandro */
                            system("cls");
                            string cpf, crm, duracao, convenio ;
                            int dia, mes, ano, horaConsulta, minutoConsulta;

                            cout << "------- INSERIR CONSULTA -------" << endl;
                            cout << "Informe o cpf do paciente: " << endl;
                            getline(cin,cpf);
                            cout << "Informe o CRM do medico" << endl;
                            getline(cin,crm);
                            
                            int posicaoPaciente = localizarPorCpf(pacientes, cpf);
                            int posicaoMedico = localizarPorCrm(medicos, crm);

                            if(posicaoPaciente < 0){
                                cout << "Paciente nao encontrado..." << endl;
                                break;
                            }else if(posicaoMedico < 0){
                                cout << "Medico nao encontrado..." << endl;
                                break;
                            }

                            cout << "----------- DATA ----------" << endl;
                            cout << "Informe o dia da consulta: " << endl;
                            cin >> dia;
                            cout << "Informe o mes da consulta:" << endl;
                            cin >> mes;
                            cout << "Informe o ano da consulta:" << endl;
                            cin >> ano;

                            if(verificacao.verificacaoData(dia, mes, ano) != 1){
                                cout << "Data invalida..." << endl;
                                break;
                            }

                            cout << "----------- HORA ----------" << endl;
                            cout << "Informe a hora consulta: " << endl;
                            cin >> horaConsulta;
                            cout << "Informe os minutos:" << endl;
                            cin >> minutoConsulta;

                            if(verificacao.verificacaoHora(horaConsulta, minutoConsulta) != 1){
                                cout << "Hora invalida invalida..." << endl;
                                break;
                            }

                            cin.ignore();
                            cout << "Informe a duracao da consulta:" << endl;
                            getline(cin, duracao);

                            cout << "----------- CONVENIO ----------" << endl;
                            cout << "Informe o convenio da consulta: " << endl;
                            getline(cin, convenio);
                        

                            //Verificar se existem consultas repetidas
                            Data data(dia, mes, ano);
                            Hora hora (horaConsulta, minutoConsulta);
                            Consulta novaConsulta(pacientes[posicaoPaciente], medicos[posicaoMedico], data, hora, duracao, convenio, 'n');

                            if(novaConsulta.verificacaoConsultaRepetida(consultas, novaConsulta)){
                                novaConsulta.incluir(consultas, novaConsulta);
                                system("cls");
                                cout << "Consulta cadastrada com sucesso!" << endl;
                            }else{
                                 cout << "Consulta ja cadastrada" << endl;
                            }
                            


                        }
                    break;

                    case 2:
                        {/* Erika */
                            
                        }
                    break;

                    case 3:
                        { /* Brenddol */
                           
                        }
                    break;

                    case 4:
                    /* Leane */
                         
                    break;

                    default:
                        cout << "Opcao invalida! " << endl;
                    break;
                }


            }while(opcaoSubMenu != 0);
            break;

            default:
                cout << "Opcao invalida! " << endl;
            break;
        }

    }while(opcao !=  0);

    return 0;
}