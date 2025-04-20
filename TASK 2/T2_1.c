void T2_1()
{
    TH1I *hist = new TH1I("h", "Track Multiplicity;Multiplicity;Count", 17, 1, 18);
    fstream file;
    file.open("multiplicities.txt",ios::in);
    int mult;
    while(1)
    {
        if(file.eof()) break;
        file>>mult;
        hist->Fill(mult);
    }
    file.close();
    hist->SetXTitle("Track Multiplicity (Number of Tracks per Event)");
    hist->SetYTitle("Number of Events");

    TCanvas *c1 = new TCanvas();
    hist->Draw();

}