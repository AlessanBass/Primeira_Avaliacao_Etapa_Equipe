#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;


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

class VerificaDados{
    private:
    int verificaTamanhoCpf;
    int verificaDigito;
    int verificaCpfCadastrado;
    int verificaData;
    int verificaCrm;

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


};

class Consulta{
    private:
    char realizada;
    string dataHora;
    string convenio;
    Paciente paciente;
    Medico medico;


    public:
      //Construtor
     Consulta(char _realizada , string _dataHora, string _convenio, Paciente _paciente, Medico _medico)
        : realizada(_realizada), dataHora(_dataHora), convenio(_convenio), paciente(_paciente), medico(_medico) {}
     
     // Getters
    char getRealizada() { return realizada; }
    string getDataHora() { return dataHora; }
    string getConvenio() { return convenio; }
    Paciente getPaciente() { return paciente; }
    Medico getMedico() { return medico; }

    // Setters
    void setRealizada(char realizada) { this->realizada = realizada; }
    void setDataHora(string dataHora) { this->dataHora = dataHora; }
    void setConvenio(string convenio) { this->convenio = convenio; }
    void setPaciente(Paciente paciente) { this->paciente = paciente; }
    void setMedico(Medico medico) { this->medico = medico; }

    bool operator==(const Consulta& other) const {
    return _realizada == other._realizada && _dataHora == other._dataHora && _convenio == other._convenio && _paciente == other._paciente && _medico == other._medico;
    }
    
    friend void excluirConsulta(vector<Consulta>& consultas, const string& CPF);
};

    void listarConsultas(const vector<Consulta>& consultas) {
  for (const auto& consulta : consultas) {
    cout << "_realizada: " << consulta._realizada << endl;
    cout << "_dataHora: " << consulta._dataHora << endl;
    cout << "_convenio: " << consulta._convenio << endl;
    cout << "_paciente: " << consulta._paciente << endl;
    cout << "_medico: " << consulta._medico << endl;
    cout << endl;
  }
}

void excluirConsulta(vector<Consulta>& consultas, const string& _paciente) {
  auto it = find_if(consultas.begin(), consultas.end(), [_paciente](const Consulta& consulta) {
    return consulta._paciente == _paciente;
  });
  if (it != consultas.end()) {
    consultas.erase(it);
  }
}

  friend void excluirConsulta(vector<Consulta>& consultas, const string& CPF);
};
    
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

int verificaConsulta(vector<Consulta> consultas, string crmProcurado, string cpfProcurado){
    for(int i = 0; i<consultas.size(); i++){
        if(medicos[i].getCrm() == crmProcurado){
            return i;
        }
    }
    return -1;
    
    for(int i = 0; i<consultas.size(); i++){
        if(pacientes[i].getCpf() == cpfProcurado){
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
                                cout << "Paciente nao encontrado..." << endl;
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

                            cout << "------- LOCALIZAR Medico -------" << endl;
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
                            string nomeMedico, crm, especialidade ;

                            cout << "------- INSERIR CONSULTA -------" << endl;
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
                        {/* Erika */
                            system("cls");
                            string crmProcurado;
                            string cpfProcurado;
                            string nomeProcurado;
                            vector<Consulta> consultas;
                            int indice;

                            cout << "-------- EXCLUIR CONSULTA --------" << endl;
                            cout << "Informe o CRM do medico: " << endl;
                            getline(cin, crmProcurado);
                            indice = localizarPorCrm(medicos, crmProcurado);
                            
                            // Lista todas as consultas do médico
                            for (const auto& consulta : consultas) {
                             if (consulta.CRM == CRM) {
                              cout << "CPF: " << consulta.CPF << endl;
                            }
                        }
                            
                            
                            cout << "Informe o CPF do paciente que nao realizou//realizara a consulta: " << endl;
                            getline(cin, cpfProcurado);
                            indice = localizarPorCpf(pacientes, cpfProcurado);

                            // Exclui o registro
                            excluirConsulta(consultas, _paciente);

                            // Lista as consultas restantes
                            cout << "Consultas restantes:" << endl;
                            listarConsultas(consultas);

                                                                    

                            if(indice != -1){
                                cout << "Condulta: " << medicos[indice].getNomeMedico() << " excluido." << endl;
                                consulta.erase(consulta.begin() + indice);
                            }else{
                                cout << "Consulta nao encontrado..." << endl;
                            }
                             cout << "----------------------------------" << endl;
                        }
                    break;

                    case 3:
                        { /* Brenddol */
                            system("cls");
                            string crmProcurado, nome, especialidade;
                            int indice, escolha;

                            cout << "------- ALTERANDO CONSULTA -------" << endl;
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
                    /* Leane */
                         system("cls");
                         cout << "------- LISTANDO CONSULTAS -------" << endl;
                        for(auto medico : medicos){
                            cout << "----------------------------------" << endl;
                            cout << "Nome: " << medico.getNomeMedico() << endl;
                            cout << "CRM: " << medico.getCrm() << endl;
                            cout << "Especialidade: " << medico.getEspecialidade() << endl;
                        }
                         cout << "----------------------------------" << endl;
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